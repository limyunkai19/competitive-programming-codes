#include <iostream>
#include <cstdio>

using namespace std;

int a[1000100];

int main(){
	freopen("atlanin.txt", "r", stdin);
	freopen("atlanout.txt", "w", stdout);
	
	int n, front = 0, back = 0, pre = 0, maxnum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a+i);
		if(a[i] > pre){
			front++;
			pre = a[i];
			maxnum = 1;
		}
		else if(a[i] == pre){
			front++;
			maxnum++;
		}
		
	}
	pre = 0;
	for(int i = n-1; i >= 0; i--){
		if(a[i] >= pre){
			back++;
			pre = a[i];
		}
	}
	
	cout << n-front-back+maxnum << endl;
}