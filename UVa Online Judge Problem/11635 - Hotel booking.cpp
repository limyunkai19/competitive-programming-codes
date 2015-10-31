#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

vector<vector<ii> > graph;
int edge_list[110][110];
vector<int> hotel_list;
bitset<10100> hotel;
vector<int> visited;
int N;

void dijkstra(int u, int idx){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	vector<int> dist(10100, 1<<30);
	pq.push(ii(0, u));
	dist[u] = 0;
	int s, t;
	while(!pq.empty()){
		s = pq.top().second; t = pq.top().first;
		pq.pop();
		if(t > 600){break;}
		if(t == dist[s]){
			for(int i = 0; i < graph[s].size(); i++){
				if(graph[s][i].second+t < dist[graph[s][i].first]){
					dist[graph[s][i].first] = graph[s][i].second+t;
					pq.push(ii(graph[s][i].second+t, graph[s][i].first));
				}
			}
		}
	}
	for(int i = 0; i < hotel_list.size(); i++){
		edge_list[i][idx] = dist[hotel_list[i]];
		edge_list[idx][i] = dist[hotel_list[i]];
	}
}


int main(){
	int n, h, a, b, k, d, m;
	int u;
	bool ans;
	while(cin >> n && n != 0){
		N = n;
		ans = false;
		hotel_list.clear();
		hotel.reset();
		graph.assign(n, vector<ii> () );
		cin >> h;
		hotel[0] = 1;
		hotel_list.push_back(0);
		for(int i = 1; i <= h; i++){
			cin >> k;
			if(k==1||k==n)continue;
			hotel[--k]=true;
			hotel_list.push_back(k);
		}
		hotel_list.push_back(n-1);
		hotel[n-1]=1;
		h = hotel_list.size();
		cin >> m;
		while(m--){
			cin >> a >> b >> k;
			graph[a-1].push_back(ii(b-1, k));
			graph[b-1].push_back(ii(a-1, k));
		}
		for(int i = 0; i < hotel_list.size(); i++){
			dijkstra(hotel_list[i], i);
		}
		visited.assign(110, -1);
		visited[0] = 0;
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			u = q.front(); q.pop();
			for(int i = 0; i < h; i++){
				if(visited[i] == -1 && edge_list[u][i] <= 600){
					visited[i] = visited[u]+1;
					q.push(i);
					if(i == h-1){
						cout << visited[i]-1 << endl;
						ans = true;
						break;
					}
				}
			}
			if(ans)break;
			
		}
		if(!ans) cout << -1 << endl;		
	}
	
	return 0;
}