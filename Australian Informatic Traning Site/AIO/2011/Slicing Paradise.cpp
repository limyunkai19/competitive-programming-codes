#include <iostream>
#include <cstdio>

using namespace std;

int tree_pos[100100], resort[100100];

int main(){
	freopen("slicein.txt", "r", stdin);
	freopen("sliceout.txt", "w", stdout);
	
	int n, park = 1, maxpark = 1, x;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		tree_pos[x] = i;
	}
	resort[0] = resort[n+1] = 1;
	
	for(int i = 1; i <= n; i++){
		if(resort[tree_pos[i]-1] == 0 && resort[tree_pos[i]+1] == 0){
			park++;
		}
		else if(resort[tree_pos[i]-1] == 1 && resort[tree_pos[i]+1] == 1){
			park--;
		}

		maxpark = max(park, maxpark);
		resort[tree_pos[i]] = 1;
	}
	
	cout << maxpark << endl;
	
	return 0;
}