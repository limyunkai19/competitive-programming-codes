#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int price1, valid1, price2, valid2, n;
int dp[100200], travel[10200];

int mincost(int day){
	if(day >= n){
		return 0;
	}
	if(dp[day] != 0){
		return dp[day];
	}
	int target1 = (upper_bound(travel, travel+n, travel[day]+valid1-1) - travel);
	int target2 = (upper_bound(travel, travel+n, travel[day]+valid2-1) - travel);
	
	return dp[day] = min(price1+mincost(target1), price2+mincost(target2));
}

int main(){
	freopen("ticketin.txt", "r", stdin);
	freopen("ticketout.txt", "w", stdout);
	cin >> price1 >> valid1 >> price2 >> valid2;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> travel[i];
	}
	cout << mincost(0) << endl;
	return 0;
}