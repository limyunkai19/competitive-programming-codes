#include <iostream>
#include <algorithm>

using namespace std;

int a[32], b[32];

int main(){
	string x, y;
	bool ans;
	while(cin >> x >> y){
		for(int i = 0; i < 32; i++){
			a[i] = b[i] = 0;
		}
		for(int i = 0; i < x.size(); i++){
			a[x[i]-'A']++;
		}
		for(int i = 0; i < y.size(); i++){
			b[y[i]-'A']++;
		}
		sort(a, a+32);
		sort(b, b+32);
		ans = true;
		for(int i = 0; i < 32; i++){
			if(a[i] != b[i]){
				ans = false;
				break;
			}
		}
		
		cout << (ans?"YES":"NO") << endl;
	}
	
	
	return 0;
}