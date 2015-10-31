#include <iostream>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int n, l;
map<int, int> house;
set<int> point;	//store interesting point in accending order;
set<int>::iterator it;

int opposite(int i){
	return (i+2*l)%(4*l);
}

int main(){
	freopen("islandin.txt", "r", stdin);
	freopen("islandout.txt", "w", stdout);
	
	long long water = 0, max_water = 0, leftppl = 0, rightppl = 0, num, ppl, pre_location;
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		//all 0-indexed;
		cin >> num >> ppl;
		num--; //0 indexing
		house[num] = ppl;
		
		//assume plant at position 0;
		if(num <= 2*l){
			water += num*ppl;
			leftppl += ppl;
		}
		else{
			water += (4*l-num)*ppl;
			rightppl += ppl;
		}
		point.insert(num);
		point.insert(opposite(num));
	}
	point.insert(0);
	max_water = max(water, max_water);
	pre_location = 0;
	for(it = ++point.begin(); it != point.end(); it++){
		rightppl += house[pre_location];
		water += rightppl*(*it - pre_location);
		rightppl -= house[opposite(*it)];
		
		leftppl -= house[pre_location];
		water -= leftppl*(*it - pre_location);
		leftppl += house[opposite(*it)];
		
		max_water = max(water, max_water);
		pre_location = *it;
	}
	cout << max_water << endl;
	
	
	return 0;
}