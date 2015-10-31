#include <iostream>
#include <cstring>

using namespace std;

int cd[110][110], dc[110][110], cat[110], dog[110];

int main(){
	int t, c, d, v, num1, num2, ans;
	char type1, type2;
	cin >> t;
	while(t--){
		cin >> c >> d >> v;
		
		memset(dog, 0, sizeof dog);
		memset(cat, 0, sizeof cat);
		memset(dc, 0, sizeof dc);
		memset(cd, 0, sizeof cd);
		while(v--){
			cin >> type1 >> num1 >> type2 >> num2;
			if(type1 == 'C'){
				cat[num1]++;
				cd[num1][num2]++;
			}
			else{
				dog[num1]++;
				dc[num1][num2]++;
			}
		}
		ans = 0;
		for(int i = 1; i <= c; i++){
			for(int j = 1; j <= d; j++){
				ans = max(ans, cat[i]+dog[j]-cd[i][j]-dc[j][i]);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}