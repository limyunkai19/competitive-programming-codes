#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[1100][1100];

int main(){
	int t, n, d, x, y, p;
	cin >> t;
	while(t--){
		cin >> d >> n;
		memset(map, 0, sizeof map);
		
		while(n--){
			cin >> x >> y >> p;
			for(int i = x+d; i >= x-d && i >= 0; i--){
				for(int j = y+d; j >= y-d && j >= 0; j--){
					map[i][j] += p;
				}
			}
		}
		p = map[0][0]-1;
		for(int i = 0; i <= 1024; i++){
			for(int j = 0; j <= 1024; j++){
				if(p < map[i][j]){
					p = map[i][j]; x=i;y=j;
				}
			}
		}
		cout << x << ' ' << y << ' ' << p << endl;
	}
	
	return 0;
}