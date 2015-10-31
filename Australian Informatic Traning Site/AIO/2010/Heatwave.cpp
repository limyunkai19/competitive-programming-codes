#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("heatin.txt", "r", stdin);
	freopen("heatout.txt", "w", stdout);
	
	int n, h, t, heat = 0, maxheat = 0;
	cin >> n >> h;
	while(n--){
		cin >> t;
		if(t >= h){
			heat++;
		}
		else{
			maxheat = max(heat, maxheat);
			heat = 0;
		}
	}
	maxheat = max(heat, maxheat);
	cout << maxheat << endl;
	
	return 0;
}