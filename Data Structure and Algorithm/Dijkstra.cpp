// Standard Dijikstra implementation
// Solve Hackerrank problem, Dijkstra: Shortest Reach 2
// link: https://www.hackerrank.com/challenges/dijkstrashortreach

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

vector<vector<ii> > graph;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b, c;
        cin >> n >> m;
        graph.assign(n, vector<ii>() );
        while(m--){
            cin >> a >> b >> c;
            graph[a-1].push_back(ii(b-1, c));
            graph[b-1].push_back(ii(a-1, c));
        }
        int s;
        cin >> s; s--;

        vector<int> dist(n, 1000000000);
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        dist[s] = 0;
        pq.push(ii(0, s));

        while(!pq.empty()){
            int u = pq.top().second, d = pq.top().first;
            pq.pop();
            if(dist[u] != d)
                continue;

            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i].first, w = graph[u][i].second;
                if(dist[u]+w < dist[v]){
                    dist[v] = dist[u]+w;
                    pq.push(ii(dist[v], v));
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(dist[i] == 0)
                continue;
            else if(dist[i] == 1000000000)
                cout << -1 << ' ';
            else
                cout << dist[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}