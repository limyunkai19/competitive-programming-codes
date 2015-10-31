#include <iostream>
#include <cstdio>

using namespace std;

int a[100100];

int main(){
	freopen("alienin.txt", "r", stdin);
	freopen("alienout.txt", "w", stdout);
	
	int n, w;
	//cin >> n >> w;
	//cin >> a[0];
	scanf("%d %d", &n, &w);
	scanf("%d", a);
	
	int start = 0, ans = 1;
	for(int i = 1; i < n; i++){
		//cin >> a[i];
		scanf("%d", a+i);
		while(a[i] - a[start] >= w){
			start++;
		}
		ans = max(i-start + 1, ans);
	}
	//cout << ans << endl;
	printf("%d\n", ans);
}