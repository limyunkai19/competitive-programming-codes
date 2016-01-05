// Bellman–Ford algorithm implementation
// Handle negative weight graph with negative cycle detection, negative node detection
// Solve UVa Online Judge problem, 10449 - Traffic
// link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1390

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n, set = 1;
    while(cin >> n){
        vector<int> busy(n);
        vector<vector<int> > graph(n, vector<int>());
        for(int i = 0; i < n; i++){
            cin >> busy[i];
        }
        int m;
        cin >> m;
        while(m--){
            int u, v;
            cin >> u >> v;
            graph[u-1].push_back(v-1);
        }

        vector<int> dist(n, 1<<30), neg_cycle(n, false);
        dist[0] = 0;
        for(int r = 0; r < 2*n+2; r++){
            for(int u = 0; u < n; u++){
                for(int i = 0; i < graph[u].size(); i++){
                    int v = graph[u][i], w = busy[v]-busy[u];
                    w = w*w*w;
                    if(dist[u]+w < dist[v]){
                        dist[v] = dist[u]+w;
                        if(r > n){
                            neg_cycle[v] = true;
                        }
                    }
                }
            }
        }
        int q;
        cin >> q;
        cout << "Set #" << set++ << endl;
        while(q--){
            int x;
            cin >> x;
            if(dist[x-1]<3 || neg_cycle[x-1] || dist[x-1] > 16000000){
                cout << '?' << endl;
            }
            else{
                cout << dist[x-1] << endl;
            }
        }
    }

    return 0;
}