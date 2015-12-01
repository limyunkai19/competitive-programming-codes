#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int x_cor[210], y_cor[210];
bool graph[210][210];

int dist(int a, int b){
	return (x_cor[a]-x_cor[b])*(x_cor[a]-x_cor[b]) + (y_cor[a]-y_cor[b])*(y_cor[a]-y_cor[b]);
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		int n;
		cin >> n;
		vector<ii> edge;
		for(int i = 0; i < n; i++){
			cin >> x_cor[i];
		}
		for(int i = 0; i < n; i++){
			cin >> y_cor[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int contradict = 0, totalfalsereport = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				if(graph[i][j] != graph[j][i]) 
					contradict++;
				else{
					edge.push_back(ii(dist(i, j), graph[i][j]));
					if(graph[i][j] == 0)
						totalfalsereport++;
				}
			}
		}
		edge.push_back(ii(0, 0));
		sort(edge.begin(), edge.end());
		int vis = 0, falsereport = totalfalsereport;
		int t = 0, f = 0;
		for(int i = 1; i < edge.size(); i++){
			if(edge[i].first != edge[i-1].first){
				if(totalfalsereport < falsereport){
					vis = edge[i-1].first;
					falsereport = totalfalsereport;
				}
			}
			falsereport += (edge[i].second?1:-1);
		}
		if(totalfalsereport < falsereport){
			vis = edge[edge.size()-1].first;
			falsereport = totalfalsereport;
		}
		cout << "Case #" << tc << ": " << vis << ' ' << falsereport+contradict/2 << endl;

	}
	return 0;
}
