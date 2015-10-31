#include <iostream>

using namespace std;

int main(){
	string a; long long ans, pow;
	while(cin >> a && a[0] != '0'){
		ans = 0; pow = 2;
		for(int i = a.size()-1; i >= 0; i--){
			ans += (a[i]-'0')*(pow-1);
			pow *= 2;
		}
		cout << ans << endl;
	}
}