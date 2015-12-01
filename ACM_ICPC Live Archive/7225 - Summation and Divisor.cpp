#include <iostream>
#include <vector>
 
using namespace std;
 
long long gcd(long long a, long long b){
	if(a == 0) return b;
	return gcd(b%a, a);
}
 
int abs(int x){
	if(x < 0) return -x;
	return x;
}
 
int main() {
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		int n;
		cin >> n;
		long long ans = 0, sum = 0;
		for(int i = 0; i < n; i++){
			int m, x;
			cin >> m;
			vector<int> a;
			while(m--){
				cin >> x;
				if(a.size() == 0) sum += (long long)x;
				a.push_back(x);
			}
			for(int i = 0; i < a.size(); i++){
				for(int j = 0; j < i; j++){
					ans = gcd(ans, abs(a[i]-a[j]));
				}
			}
		}
		ans = gcd(ans, sum);
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
