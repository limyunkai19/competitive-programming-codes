#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int vote[110], list[110][110];

int main(){
	int t;
	cin >> t;
	while(t--){
		int c, n;
		cin >> c >> n;
		memset(vote, 0, sizeof vote);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < c; j++){
				cin >> list[i][j];
			}
			vote[list[i][0]]++;
		}
		int win = n/2;
		int a, avote = 0, b, bvote = 0;
		for(int i = 1; i <= c; i++){
			if(vote[i] > avote){
				b = a; bvote = avote;
				a = i; avote = vote[i];
			}
			else if(vote[i] > bvote){
				b = i; bvote = vote[i];
			}
		}
		if(avote > win){
			cout << a << ' ' << 1 << endl;
		}
		else{
			for(int i = 0; i < n; i++){
				if(list[i][0] != a && list[i][0] != b){
					for(int j = 0; j < c; j++){
						if(list[i][j] == a){
							avote++;
							break;
						}
						else if(list[i][j] == b){
							bvote++;
							break;
						}
					}
				}
			}
			if(avote > win){
				cout << a << ' ' << 2 << endl;
			}
			else{
				cout << b << ' ' << 2 << endl;
			}
		}
		
	}
	return 0;
}