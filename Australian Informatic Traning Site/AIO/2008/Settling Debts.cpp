#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long streak[1000100], ppl[1000100], debt, x;

int main(){
	freopen("debtsin.txt", "r", stdin);
	freopen("debtsout.txt", "w", stdout);
	
	int n, streaksize = 1, start;
	scanf("%d %lld", &n, streak);
	ppl[0] = 1;
	for(int i = 2; i <= n; i++){
		scanf("%lld", &x);
		if( (x <= 0 && streak[streaksize-1] <= 0) || (x >= 0 && streak[streaksize-1] >= 0) ){
			streak[streaksize-1] += x;
		}
		else{
			streak[streaksize] = x;
			ppl[streaksize] = i;
			streaksize++;
		}
	}

	//if( (streak[0] <= 0 && streak[streaksize-1] <= 0) || (streak[0] >= 0 && streak[streaksize-1] >= 0)){
		//streak[0] += streak[streaksize-1];
		//ppl[0] = ppl[streaksize-1];
		//streaksize--;
	//}
	
	if(streak[0] < 0){
		start = 0;
	}
	else{
		start = 1;
	}
	debt = streak[start];

	for(int end = (start+1)%streaksize; end != start; end = (end+1)%streaksize){
		//cout << start << ' ' << end << ' ' << debt << endl;
		if(debt+streak[end] <= 0){
			debt += streak[end];
			//cout << debt << endl;
		}
		else{
			while(debt + streak[end] > 0){
				debt -= streak[start];
				//cout << debt << endl;
				start = (start+1)%streaksize;
			}
			if(start == (end+1)%streaksize){
				debt = streak[start];
				end = start;
			}
		}
	}
	cout << ppl[start] << endl;
}