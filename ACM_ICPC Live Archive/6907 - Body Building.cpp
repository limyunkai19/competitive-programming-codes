#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<int> visited, belltest;

int fill(int u, int color){
    visited[u] = color;
    int size = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(visited[v] == 0){
            size += fill(v, color);
        }
    }
    return size;
}


int main(){
    int t, n, m, a, b;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n >> m;
        graph.assign(n, vector<int> () );
        visited.assign(n, 0);
        belltest.assign(n, 0);

        while(m--){
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        int idx = 1, bell = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                int size = fill(i, idx);
                if(size == 2)
                    bell++;
                if(size%2 == 0 && size != 2){
                    bool isbell = true;
                    int s = 0, s1 = 0, edge[2];
                    for(int j = 0; j < n && isbell; j++){
                        if(visited[j] == idx){
                            if(graph[j].size() == size/2 -1){
                                s++;
                                if(s == 1){
                                    for(int k = 0; k < graph[j].size(); k++){
                                        belltest[graph[j][k]] = 1;
                                    }
                                    belltest[j] = 1;
                                }

                                int group = belltest[j];
                                for(int k = 0; k < graph[j].size(); k++){
                                    int v = graph[j][k];
                                    if(belltest[v] != group){
                                        isbell = false;
                                        break;
                                    }
                                }

                            }
                            else if(graph[j].size() == size/2){
                                edge[s1] = j;
                                s1++;
                                if(s1 == 3){
                                    isbell = false;
                                    break;
                                }

                            }
                            else{
                                isbell = false;
                                break;
                            }
                        }
                    }
                    for(int i = 0; i < 2; i++){
                        int out = 0;
                        for(int j = 0; j < graph[edge[i]].size(); j++){
                            int v = graph[edge[i]][j], group = belltest[edge[i]];
                            if(belltest[v] != group){
                                out++;
                            }
                        }
                        if(out != 1)
                            isbell = false;
                    }
                    if(isbell) bell++;
                }
                idx++;
            }
        }
        cout << "Case #" << tc << ": " << bell << endl;
    }

    return 0;
}