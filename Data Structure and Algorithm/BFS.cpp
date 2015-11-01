// Standard BFS implementation
// Solve Hackerrank problem, Breadth First Search: Shortest Reach
// link: https://www.hackerrank.com/challenges/bfsshortreach

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m;
        graph.assign(n, vector<int> () );
        while(m--){
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        int s;
        cin >> s; s--;
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(s);
        dist[s] = 0;

        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i];
                if(dist[v] == -1){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(dist[i] == 0)
                continue;
            else if(dist[i] == -1)
                cout << dist[i] << ' ';
            else
                cout << dist[i]*6 << ' ';
        }
        cout << endl;
    }
    return 0;
}