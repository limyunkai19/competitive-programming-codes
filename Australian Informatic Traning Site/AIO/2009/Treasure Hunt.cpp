#include <iostream>
#include <cstdio>

using namespace std;

int cave[1010][1010], ans = 1, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y){
	//cout << x << ' ' << y << endl;
	cave[x][y] = 0;
	bool used = false;
	for(int i = 0; i < 4; i++){
		if(cave[x+dx[i]][y+dy[i]]){
			dfs(x+dx[i], y+dy[i]);
			if(used){
				ans++;
			}
			used = true;
		}
	}
	return;
}

int main(){
	freopen("cavein.txt", "r", stdin);
	freopen("caveout.txt", "w", stdout);
	
	char state;
	int r, c;
	cin >> r >> c;
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cin >> state;
			if(state == '.'){
				cave[i][j] = 1;
			}
		}
	}
	
	dfs(1, 1);
	cout << ans << endl;
	
	return 0;
}