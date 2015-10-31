#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	string time;
	int h, m;
	double hangle, mangle, ans;
	while(cin >> time && time[0] != '0'){
		if(time.size() == 4){
			h = (time[0]-'0');
			m = (time[2]-'0')*10 + (time[3]-'0');
		}
		else{
			h = 10 + (time[1]-'0');
			m = (time[3]-'0')*10 + (time[4]-'0');
		}
		
		hangle = (h/12.0)*360.0 + (360.0/12.0)*(m/60.0);
		mangle = (m/60.0)*360.0;
		ans = abs(hangle - mangle);
		if(ans >= 180.0){
			ans = 360.0-ans;
		}
		printf("%0.3lf\n", ans);
	}
	
	return 0;
}