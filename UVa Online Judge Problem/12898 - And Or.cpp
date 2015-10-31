#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
	long long a, b, diff, andans, orans;
	int t;
	//cin >> t;
	scanf("%d",&t);
	for(int tc = 1; tc <= t; tc++){
		//cin >> a >> b;
		scanf("%lld%lld", &a, &b);
		diff = b-a;
		andans = orans = 0;
		for(long long i = 1; i <= b; i = i<<1){
			bool bita = a&i, bitb = b&i;
			if(bita != bitb){
				orans |= i;
			}
			else if(diff >= i){
				orans |= i;
			}
			else{
				//no change
				if(bita == 1){
					andans |= i;
					orans  |= i;
				}
			}
		}
		//cout << "Case " << tc << ": " << orans << ' ' << andans << endl;
		printf("Case %d: %lld %lld\n", tc, orans, andans);
	}
	return 0;
}