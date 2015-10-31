#include <iostream>
#include <cstdio>

using namespace std;

int min_req[100100], hula[100100];

int main(){
	freopen("dancein.txt", "r", stdin);
	freopen("danceout.txt", "w", stdout);
	
	int n, t, ans = 0, a, b;
	cin >> n >> t;
	for(int i = 0; i < t; i++){
		cin >> a >> b;
		hula[a]--;
		hula[b]++;
		
		min_req[a] = min(hula[a], min_req[a]);
	}
	for(int i = 1; i <= n; i++){
		ans += -min_req[i];
	}
	cout << ans << endl;
	
	return 0;
}