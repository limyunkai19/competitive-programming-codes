#include <iostream>
#include <cstdio>

using namespace std;

long long num[500010];

int main(){
	int t, n, a, b, ans;
	long long sum, x, y;
	cin >> t;
	while(t--){
		cin >> n >> x;
		for(int i = 0; i < n; i++){
			cin >> num[i];
		}
		a = 0;
		while(num[a] < 1 && a < n){
			if(num[a] >= x){
				cout << 1 << endl;
				break;
			}
			a++;
		}
		if(a == n){cout << -1 << endl;continue;}
		if(num[a] >= x){cout << 1 << endl;continue;}
		if(a == n-1){cout << -1 << endl;continue;}
		b = a+1;
		ans = n+1;
		sum = num[a];
		while(b < n){
			while(sum < x && b < n){
				sum += num[b++];
			}
			if(b-a < ans && sum >= x){
				ans = b-a;
				//cout << a << ' ' << b-1 << ' ' << sum << endl;
			}
			sum -= num[a];
			a++;
			while(num[a] < 1 && a < n){
				sum -= num[a];
				a++;
			}
			if(a >= b){
				sum = num[a];
				b = a+1;
			}
		}
		/*while(a < n){
			sum -= num[a];
			a++;
			if(sum >= x && b-a+1 < ans){
				ans = b-a+1;
			}
		}*/
		cout << ((ans==(n+1))?-1:ans) << endl;
	}
}