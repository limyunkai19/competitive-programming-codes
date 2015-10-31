#include <iostream>
#include <cstdio>

using namespace std;

int rcard[10100], scard[10100];

int main(){
	freopen("snapin.txt", "r", stdin);
	freopen("snapout.txt", "w", stdout);
	
	int r, s, x, ans = 0;
	cin >> r >> s;
	while(r--){
		cin >> x;
		rcard[x]++;
	}
	while(s--){
		cin >> x;
		scard[x]++;
	}
	for(int i = 1; i <= 10000; i++){
		ans += rcard[i]*scard[i];
	}
	cout << ans << endl;
}