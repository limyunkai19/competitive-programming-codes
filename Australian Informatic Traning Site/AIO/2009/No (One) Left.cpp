#include <iostream>
#include <cstdio>

using namespace std;

const int toobig = 200000, toosmall = -1;
int miny[10100], maxy[10100];

int abs(int x){
	if(x < 0) return -x;
	return x;
}

int main(){
	freopen("leftin.txt", "r", stdin);
	freopen("leftout.txt", "w", stdout);
	
	for(int i = 0; i < 10010; i++){
		miny[i] = toobig;
		maxy[i] = toosmall;
	}
	
	int n, x, y, minx = toobig;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		minx = min(minx, x);
		miny[x] = min(miny[x], y); 	//only care about the highest and lowest trolley
		maxy[x] = max(maxy[x], y); 	//certainly collect all centre trolley when collecting up and down
	}
	
	int preup = 0, predown = 0, prex = minx, length, nowup, nowdown;
	for(int i = minx+1; i < 10010; i++){
		if(maxy[i] != toosmall){
			length = maxy[prex] - miny[prex];
			nowup   = min(predown + length + abs(maxy[i]-maxy[prex]) + (i-prex),  	//travel from previous down to now up
			              preup   + length + abs(maxy[i]-miny[prex]) + (i-prex)); 	//travel from previous up to now up
			
			nowdown = min(predown + length + abs(miny[i]-maxy[prex]) + (i-prex),
			              preup   + length + abs(miny[i]-miny[prex]) + (i-prex));
			preup = nowup;
			predown = nowdown;
			prex = i;
		}
	}
	cout << min(preup, predown)+(maxy[prex]-miny[prex]) << endl;
}