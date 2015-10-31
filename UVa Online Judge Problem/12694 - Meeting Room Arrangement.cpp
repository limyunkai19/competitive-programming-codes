#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<bool> > end;

int main(){
	int tc, a, b, ans;
	cin >> tc;
	while(tc--){
		end.assign(11, vector<bool> (10, 0));
		while(cin >> a >> b && b != 0){
			end[b][a] = 1;
		}
		ans = 0;
		a = 0; b = 1;
		while(b <= 10){
			for(int i = 0; i <= 9; i++){
				//cout << b << ' ' << i << ' ' << end[b][i] << ' ' << ans << endl;
				if(end[b][i] && i >= a){
					ans++;
					a = b;
					break;
				}
			}
			b++;
		}
		cout << ans << endl;
	}
	
	return 0;
}