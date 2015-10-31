#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
 
using namespace std;
 
vector<vector<int> > graph;
int network[60][60], parent[60];
 
int sendflow(int v, int minedge){
	if(parent[v] == v) return minedge;
 
	int f = sendflow(parent[v], min(minedge, network[parent[v]][v]));
	network[parent[v]][v] -= f;
	network[v][parent[v]] += f;
	//cout << parent[v] << ' ' << v << ' ' << f << endl;
	return f;
}
 
 
int main() {
	int n, m, u, v, k;
	while(cin >> n >> m && n != 0){
		graph.assign(n, vector<int> ());
		memset(network, 0, sizeof network);
		while(m--){
			cin >> u >> v >> k;
			u--; v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
			network[u][v] = network[v][u] = k;
		}
		// min cut = max flow
		// source = 1 sink = 2
		int maxflow = 0, flow = 1;
		while(flow != 0){
			// find a path using bfs to the sink
			queue<int> q;
			memset(parent, -1, sizeof parent);
			q.push(0);
			flow = 0;
			parent[0] = 0;
			while(!q.empty()){
				u = q.front(); q.pop();
				for(int i = 0; i < graph[u].size(); i++){
					v = graph[u][i];
					if(parent[v] == -1 && network[u][v] > 0){ // not visited
						parent[v] = u;
						q.push(v);
						if(v == 1){	// reached sink
							flow = sendflow(v, 2000000000);
							maxflow += flow;
							// quit this bfs and continue to next bfs
							while(!q.empty()) q.pop();
							break;
						}
					}
				}
			}
		}
		//cout << maxflow << endl;
		bool visited[60] = {0};
		visited[0] = true;
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			u = q.front(); q.pop();
			for(int i = 0; i < graph[u].size(); i++){
				v = graph[u][i];
				if(!visited[v] && network[u][v]){
					visited[v] = true;
					q.push(v);
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < graph[i].size(); j++){
				if(visited[i] && !visited[graph[i][j]]){
					cout << i+1 << ' ' << graph[i][j]+1 << endl;
				}
			}
		}
		cout << endl;
	}
 
	return 0;
}