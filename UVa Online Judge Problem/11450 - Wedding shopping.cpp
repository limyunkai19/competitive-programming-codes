#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<bool> possibleA(300, 0), possibleB(300, 0), empty(300, 0);

int main(){
	int t, money, model, n, price, k;
	cin >> t;
	while(t--){
		cin >> money >> model;
		cin >> n;
		possibleA = empty;
		possibleB = empty;
		while(n--){
			cin >> price;
			if(price <= money){
				possibleA[price] = true;
			}
		}
		// for(int i = 0; i <= money; i++){
				// cout << possibleA[i] << ' ';
		// }
			// cout << endl;
		
		while(--model){
			cin >> n;
			while(n--){
				cin >> price;
				k = money-price;
				for(int i = 0; i <= k; i++){
					if(possibleA[i]){
						possibleB[i+price] = true;
					}
				}
			}
			possibleA = possibleB;
			possibleB = empty;
			// for(int i = 0; i <= money; i++){
				// cout << possibleA[i] << ' ';
			// }
			// cout << endl;
		}
		for(k = money; k >= 0; k--){
			if(possibleA[k]){
				cout << k << endl;
				break;
			}
		}
		if(k <= 0){
			cout << "no solution" << endl;
		}
	}
	
	return 0;
}