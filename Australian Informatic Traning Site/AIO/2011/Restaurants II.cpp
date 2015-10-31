#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dishA, dishB;

int main(){
	freopen("restin.txt", "r", stdin);
	freopen("restout.txt", "w", stdout);
	
	int n, a, b, happy = 0, x, y;
	
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		if(x <= 0 && y <= 0){continue;}
		if(x > y){
			dishA.push_back(x - max(0, y));
			happy += x;
		}
		else{
			dishB.push_back(y - max(0, x));
			happy += y;
		}
	}
	//if one of them are over limit try move to other side
	if(dishA.size() > a){
		sort(dishA.begin(), dishA.end());
		for(int i = 0; i < dishA.size()-a; i++){
			happy -= dishA[i];
		}
	}
	else if(dishB.size() > b){
		sort(dishB.begin(), dishB.end());
		for(int i = 0; i < dishB.size()-b; i++){
			happy -= dishB[i];
		}
	}
	cout << happy << endl;
	
	return 0;
}