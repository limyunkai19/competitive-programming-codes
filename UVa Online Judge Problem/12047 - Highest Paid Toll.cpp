#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

void dijikstra(int s, vector<vector<ii> >& graph, vector<long long>& dist){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	dist[s] = 0;
	while(!pq.empty()){
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if(dist[u] != d) continue;
		for(int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i].first, w = graph[u][i].second;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u]+w;
				pq.push(ii(dist[v], v));
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--){
		int n, m, s, t;
		long long p;
		cin >> n >> m >> s >> t >> p;
		vector<vector<ii> > graph(n, vector<ii>() ), rgraph(n, vector<ii>() );
		
		while(m--){
			int a, b, w;
			cin >> a >> b >> w;
			a--;b--;
			graph[a].push_back(ii(b, w));
			rgraph[b].push_back(ii(a, w));
		}
		
		vector<long long> dist_s(n, 1000000000000000), dist_t(n, 1000000000000000);
		dijikstra(s-1, graph, dist_s);
		dijikstra(t-1, rgraph, dist_t);
		
		int ans = -1;
		for(int u = 0; u < n; u++){
			for(int i = 0; i < graph[u].size(); i++){
				int v = graph[u][i].first, w = graph[u][i].second;
				if(dist_s[u]+(long long)w+dist_t[v] <= p){
					ans = max(ans, w);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
