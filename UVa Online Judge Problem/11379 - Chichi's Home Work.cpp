#include <iostream>

using namespace std;

long long cat[1010], f[1010][1010], g[1010][1010];
//cat[i] is the ith catalan number
//f[n][k] is the number of ways to place n circle such that kth circle doesnt contain anything
//g[n][k] is the number of ways to place n circle such that kth circle contain at least 1 circle
//it is related by:
//f[n][k] = cat[n]-g[n][k];
//g[n][k] = f[n-1][k] + g[n-1][k]; 
//if k = n then f[n][k] = cat[n-1] and g[n][k] = cat[n]-cat[n-1] <-- compute this first

int main(){
	cat[0] = 1;
	for(long long i = 1; i <= 1000; i++){
		cat[i] = ((4*i-2)*cat[i-1])/(i+1);
		
		f[i][i] = cat[i-1]%1000000000;
		g[i][i] = (cat[i]-cat[i-1])%1000000000;
		
		cat[i] %= 1000000000;
	}
	
	for(int n = 1; n <= 1000; n++){
		for(int k = 1; k < n; k++){
			g[n][k] = (f[n-1][k] + g[n-1][k])%1000000000;
			f[n][k] = (cat[n] - g[n][k])%1000000000;
			if(f[n][k] < 0){
				f[n][k] += 1000000000;
			}
		}
	}
	int n, x, y;
	long long ans;
	while(cin >> n >> x >> y){
		ans = 0;
		for(int i = y-x; i <= n - x; i++){
			ans += f[n-i][x]*cat[i];
			cout << n-i << ' ' << f[n-i][x] << ' ' << cat[i] << endl;
		}
		ans %= 1000000000;
		cout << ans << endl;
	}
}