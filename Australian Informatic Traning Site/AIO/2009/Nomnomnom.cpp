#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("nomin.txt", "r", stdin);
	freopen("nomout.txt", "w", stdout);
	
	int n, ans = 0, hippo = 0, prehippo = 0, dish;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> dish;
		hippo += dish;
		if(hippo >= prehippo){
			ans++;
			prehippo = hippo;
			hippo = 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}