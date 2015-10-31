#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int x[22], y[22], n;
double dist[22][22];
vector<double> dp;

double distant(int i, int j){
//cout << hypot(x[i]-x[j], y[i]-y[j]) << endl;
	return hypot(x[i]-x[j], y[i]-y[j]);
}

double match(int bitmask){
	if(dp[bitmask] > -0.5){
		return dp[bitmask];
	}
	if(bitmask == 0){
		return dp[bitmask] = 0;
	}
	double ans = 2000000000.0;
	for(int i = 0; i < 2*n; i++){
		if(bitmask&(1<<i)){
			for(int j = i+1; j < 2*n; j++){
				if(bitmask&(1<<j)){
					ans = min(ans, match(bitmask^(1<<i)^(1<<j))+dist[i][j]);
				}
			}
			break;
		}
	}
	return dp[bitmask] = ans;
	
}

int main(){
	string dummy; int t = 0;
	while( (cin >> n) && n!=0){
		for(int i = 0; i < 2*n; i++){
			cin >> dummy >> x[i] >> y[i];
		}
		dp.assign(1<<(2*n), -1);
		for(int i = 0; i < 2*n; i++){
			for(int j = i; j < 2*n; j++){
				dist[i][j] = dist[j][i] = distant(i, j);
			}
		}
		printf("Case %d: %0.2lf\n", ++t, match( (1<<(2*n))-1 )  );
	}
	
	
}