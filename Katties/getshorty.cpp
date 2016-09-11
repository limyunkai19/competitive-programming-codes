#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<double, int> di;

int main() {
    int n, m;
    while(cin >> n >> m && n != 0){
        vector<vector<di> > graph(n, vector<di> ());
        priority_queue<di> pq;

        while(m--){
            int u, v;
            double f;
            cin >> u >> v >> f;
            graph[u].push_back(di(f, v));
            graph[v].push_back(di(f, u));
        }

        pq.push(di(1, 0));
        vector<double> dist(n, 0);
        dist[0] = 1;
        while(!pq.empty()){
            int u = pq.top().second;
            double d = pq.top().first;
            pq.pop();

            if(d == dist[u]){
                for(int i = 0; i < graph[u].size(); i++){
                    int v = graph[u][i].second;
                    double f = graph[u][i].first;

                    if(d*f > dist[v]){
                        dist[v] = d*f;
                        pq.push(di(d*f, v));
                    }
                }
            }
        }
        printf("%0.4lf\n", dist[n-1]);
    }
    return 0;
}