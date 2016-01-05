#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main(){
    int n, m;
    while(cin >> n >> m && n != 0){
        int cost = 0;
        vector<vector<ii> > graph(n, vector<ii>());
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(ii(v, w));
            graph[v].push_back(ii(u, w));
            cost += w;
        }

        vector<bool> visited(n, false);
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, 0));

        while(!pq.empty()){
            int w = pq.top().first, u = pq.top().second;
            pq.pop();
            if(visited[u]) continue;

            visited[u] = true;
            cost -= w;
            for(int i = 0; i < graph[u].size(); i++){
                if(!visited[graph[u][i].first])
                    pq.push(ii(graph[u][i].second, graph[u][i].first));
            }
        }
        cout << cost << endl;
    }

    return 0;
}