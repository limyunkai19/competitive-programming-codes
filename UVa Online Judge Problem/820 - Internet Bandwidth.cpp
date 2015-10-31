#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int flow[200][200], p[200];
vector<vector<int> > graph;
queue<int> q;

int sendflow(int v, int min_edge){
	if(p[v] == v) return min_edge;
	
	int f = sendflow(p[v], min(min_edge, flow[p[v]][v]) );
	flow[v][p[v]] += f;
	flow[p[v]][v] -= f;
	return f;
}

int main(){
	int n, source, destination, e, a, b, x, f, tc = 1;
	while(cin >> n && n != 0){
		memset(flow, 0, sizeof flow);
		graph.assign(n, vector<int> () );
		
		cin >> source >> destination >> e;
		source--; destination--;
		while(e--){
			cin >> a >> b >> x;
			graph[a-1].push_back(b-1);	flow[a-1][b-1] += x;
			graph[b-1].push_back(a-1);	flow[b-1][a-1] += x;
		}
		
		int maxflow = 0, f = 10000;
		while(f != 0){
			//bfs
			q.push(source);
			memset(p, -1, sizeof p);
			p[source] = source;
			f = 0;
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(int i = 0; i < graph[u].size(); i++){
					int v = graph[u][i];
					if(flow[u][v] > 0 && p[v] == -1){
						q.push(v);
						p[v] = u;
						if(v == destination){
							f = sendflow(v, 100000000);
							maxflow += f;
							q = queue<int> ();
							break;
						}
					}
				}
			}
		}
		cout << "Network " << tc++ << endl << "The bandwidth is " << maxflow << ".\n\n";		
	}
	
	return 0;
}