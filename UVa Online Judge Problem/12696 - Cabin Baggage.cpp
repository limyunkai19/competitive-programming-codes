#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int tc, ans = 0, a;
	float l, w, d, wt;
	cin >> tc;
	while(tc--){
		cin >> l >> w >> d >> wt;
		cout << (a = (( (l+w+d <= 125.0) || (l <= 56.0 && w <= 45.0 && d <= 25.0)  )&& wt <= 7.0) ) << endl;
		ans += a;
	}
	cout << ans << endl;
	return 0;
}