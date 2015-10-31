#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int car[2010];
int n;

int find_length(int start){
	//memset(lis, -1, sizeof lis);
	//memset(lds, -1, sizeof lds);
	vector<int> lis, lds;
	vector<int>::iterator it;
	vector<int>::reverse_iterator rit;
	for(int i = start+1; i < n; i++){
		if(car[i] < car[start]){ // decreasing 
			//linear search first
			/*
			for(int j = 0; j <= lds_len+1; j++){
				if(lds[j] < car[i]){
					lds[j] = car[i];
					break;
				}
			}
			if(lds[lds_len+1] != -1){lds_len++;}
			*/
			//binary search
			rit = lower_bound(lds.rbegin(), lds.rend(), car[i]);
			if(rit == lds.rbegin()){
				lds.push_back(car[i]);
			}
			else{
				rit--;
				*rit = car[i];
			}
		} 
		else{					 //increasing
			/*
			for(int j = 0; j <= lis_len+1; j++){
				if(lis[j] > car[i]){
					lis[j] = car[i];
					break;
				}
			}
			if(lis[lis_len] < car[i]){
				lis[++lis_len] = car[i];
			}
			*/
			it = lower_bound(lis.begin(), lis.end(), car[i]);
			if(it == lis.end()){
				lis.push_back(car[i]);
			}
			else{
				*it = car[i];
			}
		}
	}
	return lis.size()+lds.size()+1;
}

int main(){
	int tc, ans;
	cin >> tc;
	while(tc--){
		ans = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> car[i];
		}
		
		/*
		for(int i = 0; i < n; i++){
			ans = max(ans, find_length(i));
		}
		*/
		
		// algo with 1 pass lis lds, here lis[i] is lis where i is starting point;
		int lis[2010], lds[2010];
		lis[n] = 0; lds[n] = 0;
		for(int j = n-1; j >= 0; j--){
			int maxlis = 0, maxlds = 0;
			for(int k = j+1; k < n; k++){
				if(car[j] > car[k]){
					maxlds = max(maxlds, lds[k]);
				}
				else{
					maxlis = max(maxlis, lis[k]);
				}
			}
			lis[j] = maxlis+1;
			lds[j] = maxlds+1;
			ans = max(ans, lis[j]+lds[j]-1);
		} 
		
		cout << ans << endl;
	}
}