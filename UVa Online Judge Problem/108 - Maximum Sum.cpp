/*

0(N^4) algo

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[105][105], sum[105][105];

int main() {
	int n, sum, max_sum = -128*100*100;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1]; 
		}
	}
	
	for(int sx = 1; sx <= n; sx++){
		for(int sy = 1; sy <= n; sy++){
			for(int ex = sx; ex <= n; ex++){
				for(int ey = sy; ey <= n; ey++){
					sum = a[ex][ey] - a[sx-1][ey] - a[ex][sy-1] + a[sx-1][sy-1];
					max_sum = max(sum, max_sum);
				}
			}
		}
	}
	cout << max_sum << endl;
	
	return 0;
}

*/



//O(N^3) with the help of kadane algo

#include <iostream>
using namespace std;

int n, a[105][105], arr[105];

int find_max_sum(int b[]){
	int sum, max_sum = -128*100*100, cur, x;
	x = 0;
	sum = b[0];
	while(b[x] < 0 && x < n){
		x++;
		sum = min(sum, b[x]);
	}
	if(x == n){
		return sum;
	}
	cur = 0;
	for(int i = x; i < n; i++){
		cur += b[i];
		max_sum = max(cur, max_sum);
		if(cur < 0){
			cur = 0;
		}
	}
	return max_sum;
}

int main() {
	int max_sum = -128*100*100, sum, cur, x, y;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	
	for(int r1 = 0; r1 < n; r1++){
		for(int i = 0; i < n; i++){
			arr[i] = a[r1][i];
		}
		max_sum = max(max_sum, find_max_sum(arr));
		
		for(int r2 = r1+1; r2 < n; r2++){
			for(int i = 0; i < n; i++){
				arr[i] += a[r2][i]; 
			}
			max_sum = max(max_sum, find_max_sum(arr));
		}
	}
	cout << max_sum << endl;
	return 0;
}