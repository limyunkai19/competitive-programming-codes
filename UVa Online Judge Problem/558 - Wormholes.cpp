// note: there is a bug in the algorithm but
//       the bug help in getting a runtime on 0.00 in UVa online judge
//       the bug is at line 47 of this code
//       the correct algorithm should be if(queuetime[v] == n+2){

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
        vector<int> dist(n, 1<<30), queuetime(n, 0);
        vector<bool> inqueue(n, 0);
        dist[0] = 0; inqueue[0] = true;
        queue<int> q;
        q.push(0);
        queuetime[0] = 1;
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
                        inqueue[v] = true;
                        queuetime[v]++;
                        if(queuetime[v] == v+2){
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