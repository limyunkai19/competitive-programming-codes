#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main() {
    int n, m;
    while(cin >> n >> m && n != 0){
        vector<vector<ii> > graph(n, vector<ii> ());
        while(m--){
            int u, v, x;
            cin >> u >> v >> x;
            graph[u].push_back(ii(v, x));
            graph[v].push_back(ii(u, x));
        }

        int mst = 0;
        priority_queue<iii, vector<iii>, greater<iii> > pq;
        pq.push(iii(0, ii(0, 0)));
        vector<bool> visited(n, false);
        vector<ii> edge;

        while(!pq.empty()){
            int u = pq.top().second.first, pu = pq.top().second.second, w = pq.top().first;
            pq.pop();
            if(!visited[u]){
                mst += w;
                edge.push_back(ii(min(u, pu), max(u, pu)));
                visited[u] = true;
                for(int i = 0; i < graph[u].size(); i++){
                    int v = graph[u][i].first, d = graph[u][i].second;
                    if(!visited[v])
                        pq.push(iii(d, ii(v, u)));
                }
            }
        }

        sort(edge.begin(), edge.end());
        if(edge.size() != n){
            cout << "impossible" << endl;
        }
        else{
            cout << mst << endl;
            for(int i = 1; i < edge.size(); i++){
                cout << edge[i].first << ' ' << edge[i].second << endl;
            }
        }
    }

    return 0;
}