#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main() {
	int tc;
	cin >> tc;
	while(tc--){
		int n, e, limit, m;
		cin >> n >> e >> limit >> m;
		int u, v, t;
		vector<vector<ii> > graph(n, vector<ii>() );

		while(m--){
			cin >> u >> v >> t;
			graph[v-1].push_back(ii(u-1, t));
		}
		vector<int> dist(n, 1<<30);
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		dist[e-1] = 0;
		pq.push(ii(0, e-1));
		while(!pq.empty()){
			int u = pq.top().second, d = pq.top().first;
			pq.pop();
			if(dist[u] != d){
				continue;
			}
			for(int i = 0; i < graph[u].size(); i++){
				int v = graph[u][i].first, w = graph[u][i].second;
				if(dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					pq.push(ii(dist[v], v));
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(dist[i] <= limit){
				ans++;
			}
		}
		cout << ans << endl;
		if(tc != 0) cout << endl;
	}
	
	return 0;
}
