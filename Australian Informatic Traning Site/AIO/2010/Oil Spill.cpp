#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

char graph[3000][3000];
int days[3000][3000], visit[3000][3000];

int main(){
	freopen("oilin.txt", "r", stdin);
	freopen("oilout.txt", "w", stdout);
	
	int r, c, k, starti, startj;
	cin >> r >> c >> k;
	for(int i = 0; i <= c+1; i++){
		graph[0][i] = graph[r+1][i] = '#';
		visit[0][i] = visit[r+1][i] = true;
	}
	for(int i = 1; i <= r; i++){
		graph[i][0] = graph[i][c+1] = '#';
		visit[i][0] = visit[i][c+1] = true;
	}
	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			//scanf("%c", &graph[i][j]);
			cin >> graph[i][j];
			if(graph[i][j] == '#'){
				visit[i][j] = true;
			}
			if(graph[i][j] == '$'){
				starti = i; startj = j;
			}
		}
	}
	
	int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
	queue<ii> q;
	q.push(ii(starti, startj)); visit[starti][startj] = true;
	ii now;
	while(!q.empty()){
		now = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			if(!visit[now.first+dx[i]][now.second+dy[i]]){
				days[now.first+dx[i]][now.second+dy[i]] = days[now.first][now.second]+1;
				visit[now.first+dx[i]][now.second+dy[i]] = true;
				q.push(ii(now.first+dx[i], now.second+dy[i]));
			}
		}
	}
	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			if(graph[i][j] == '.'){
				if(days[i][j] <= k && days[i][j] != 0){
					cout << '*';
				}
				else{
					cout << '.';
				}
			}
			else{
				cout << graph[i][j];
			}
		}
		cout << endl;
	}
	
	return 0;
}