#include <iostream>

using namespace std;

int a[10010];

int main(){
	int n, x, ans, cur;
	while(cin >> n && n != 0){
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		x = 0;
		while(x < n && a[x] <= 0){
			x++;
		}
		if(x == n){
			cout << "Losing streak." << endl;
			continue;
		}
		cur = ans = 0;
		for(; x < n; x++){
			cur += a[x];
			if(cur < 0){
				cur = 0;
			}
			ans = max(ans, cur);
		}
		cout << "The maximum winning streak is " << ans << "." << endl;
	}
	return 0;
}