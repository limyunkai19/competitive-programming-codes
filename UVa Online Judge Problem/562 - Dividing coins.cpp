#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

bool dpold[50010], dpnew[50010];

int main() {
	int t, n, x, max_coin;
	cin >> t;
	while(t--){
		memset(dpold, 0, sizeof dpold);
		memset(dpnew, 0, sizeof dpnew);
		dpold[0] = true;
		max_coin = 0;
		cin >> n;
		while(n--){
			cin >> x;
			for(int i = 0; i <= max_coin; i++){
				if(dpold[i]){
					dpnew[i+x] = true;
					dpnew[abs(i-x)] = true;
				}
			}
			max_coin += x;
			for(int i = 0; i <= max_coin; i++){
				dpold[i] = dpnew[i];
				dpnew[i] = false;
			}
		}
		for(int i = 0; i <= max_coin; i++){
			if(dpold[i]){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}