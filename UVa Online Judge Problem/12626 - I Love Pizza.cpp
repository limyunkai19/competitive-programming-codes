#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string a;
	int t, ans, alpha[40];
	int pizza[6] = {'M', 'A', 'R', 'G', 'I', 'T'}, num[6] = {1, 3, 2, 1, 1, 1};
	cin >> t;
	while(t--){
		memset(alpha, 0, sizeof alpha);
		ans = 1000000;
		cin >> a;
		for(int i = 0; i < a.size(); i++){
			alpha[a[i]-'A']++;
		}
		for(int i = 0; i < 6; i++){
			ans = min(ans, alpha[pizza[i]-'A']/num[i]);	
		}
		cout << ans << endl;
	}
	return 0;
}