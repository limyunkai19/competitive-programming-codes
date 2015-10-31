#include <iostream>

using namespace std;

int price[1010], weight[1010], max_price[35];

int main(){
	int t, n, ppl, sum;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i <= 30; i++){
			max_price[i] = 0;
		}
		for(int i =0; i < n; i++){
			cin >> price[i] >> weight[i];
			for(int p = 30; p >= 0; p--){
				if(p + weight[i] <= 30 && max_price[p+weight[i]] < max_price[p]+price[i]){
					max_price[p+weight[i]] = max_price[p]+price[i];
				}
			}
		}
		cin >> ppl;
		sum = 0;
		for(int i = 0; i < ppl; i++){
			cin >> n;
			sum += max_price[n];
		}
		cout << sum << endl;
	}
	
	return 0;
}