#include <iostream>

using namespace std;

int ways[50010][3];

int main(){
	for(int i = 1; i*i <= 50000; i++){
		ways[i*i][0] = i;
	}
	for(int i = 1; i < 3; i++){
		for(int num = 50000; num >= 1; num--){
			if(ways[num][i-1] > 0 && ways[num][i] == 0){
				for(int j = 1; j <= ways[num][i-1] && num+j*j <= 50000; j++){
					if(ways[num+j*j][0] == 0){
						ways[num+j*j][0] = ways[num][0];
						ways[num+j*j][1] = ways[num][1];
						ways[num+j*j][i] = j;
					}
				}
			}
		} 
	}
	
	
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		if(ways[n][0] > 0 || n==0){
			cout << ways[n][2] << ' ' << ways[n][1] << ' ' << ways[n][0] << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	return 0;
}