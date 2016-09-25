// Shortest Path Faster Algorithm implementation
// Handle negative weight graph with negative cycle detection
// Solve UVa Online Judge problem, 558 - Wormholes
// link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=499

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

vector<vector<ii> > graph;

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        graph.assign(n, vector<ii> () );
        while(m--){
            int a, b, t;
            cin >> a >> b >> t;
            graph[a].push_back(ii(b, t));
        }
        vector<int> dist(n, 1<<30);     dist[0] = 0;
        vector<int> queuetime(n, 0);    queuetime[0] = 1;
        vector<bool> inqueue(n, 0);     inqueue[0] = true;
        queue<int> q;                   q.push(0);
        bool negativecycle = false;

        while(!q.empty() && !negativecycle){
            int u = q.front(); q.pop();
            inqueue[u] = false;

            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i].first, w = graph[u][i].second;

                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;

                    if(!inqueue[v]){
                        q.push(v);
                        queuetime[v]++;
                        inqueue[v] = true;

                        if(queuetime[v] == n+2){
                            negativecycle = true;
                            break;
                        }
                    }
                }
            }
        }
        cout << (negativecycle?"possible":"not possible") << endl;
    }
    return 0;
}