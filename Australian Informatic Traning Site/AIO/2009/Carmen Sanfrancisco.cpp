#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

vector<vector<ii> > graph;
int sequence[510], possible[510][510];
int n, e;

bool dfs(int u, int step){
	if(step == e){
		return possible[u][step] = true;
	}
	if(possible[u][step] != -1){
		return possible[u][step];
	}
	
	int ans = false;
	for(int i = 0; i < graph[u].size(); i++){
		if(graph[u][i].second == sequence[step]){
			if(dfs(graph[u][i].first, step+1)){
				return possible[u][step] = true;
			}
		}
	}
	return possible[u][step] = false;
}

int main(){
	freopen("wherein.txt", "r", stdin);
	freopen("whereout.txt", "w", stdout);
	
	//cin >> n >> e;
	scanf("%d %d", &n, &e);
	
	graph.assign(n, vector<ii> () );
	memset(possible, -1, sizeof possible);
	int a, b, t;
	for(int i = 0; i < e; i++){
		//cin >> a >> b >> t;
		scanf("%d %d %d", &a, &b, &t);
		graph[a-1].push_back(ii(b-1, t));
		graph[b-1].push_back(ii(a-1, t));
	}
	
	//cin >> e;
	scanf("%d", &e);
	for(int i = 0; i < e; i++){
		//cin >> sequence[i];
		scanf("%d", sequence+e-1-i);
	}
	
	for(int i = 0; i < n; i++){
		dfs(i, 0);
	}
	
	bool gotans = false;
	for(int i = 0; i < n; i++){
		if(possible[i][0] == true){
			//cout << i+1 << endl;
			printf("%d\n", i+1);
			gotans = true;
		}
	}
	if(!gotans){
		//cout << "Impossible" << endl;
		printf("Impossible\n");
	}
	
	return 0;
}