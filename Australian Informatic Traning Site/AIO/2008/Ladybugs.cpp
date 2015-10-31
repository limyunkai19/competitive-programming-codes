#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("ladyin.txt", "r", stdin);
	freopen("ladyout.txt", "w", stdout);
	
	int n, x, maxx = -1, minx = 2000000000;
	//cin >> n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		//cin >> x;
		scanf("%d", &x);
		maxx = max(x, maxx);
		minx = min(x, minx);
	}
	
	printf("%d\n", maxx-minx+1);
}