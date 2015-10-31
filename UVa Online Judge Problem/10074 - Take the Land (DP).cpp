#include <iostream>

using namespace std;

bool a[200][200];
int height[200][200], lefts[200][200], leftrec[200][200], rights[200][200], rightrec[200][200];

int main(){
	int m, n, maxarea, area, top;
	while(cin >> m >> n && m != 0){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
				a[i][j] = !a[i][j];
				height[i][j] = ((a[i][j] == 1)?(height[i-1][j]+1):0);
				lefts[i][j] = (a[i][j-1]==0?j:lefts[i][j-1]);
			}
			a[i][n+1] = 0;
		}
		maxarea = 0;
		for(int i = 1; i <= m; i++){
			for(int j = n; j >= 1; j--){
				rights[i][j] = (a[i][j+1] == 0?j:rights[i][j+1]);
				
				//we can start calculate leftrec and rightrec in this loop since we have all the value calculated
				if(height[i][j] == 1){
					leftrec[i][j] = lefts[i][j];
					rightrec[i][j] = rights[i][j];
				}
				else{
					leftrec[i][j] = max(lefts[i][j], leftrec[i-1][j]);
					rightrec[i][j] = min(rights[i][j], rightrec[i-1][j]);
				}
				
				//to save time we can even calculate area in this loop since all the value had calulated
				area = height[i][j]*(rightrec[i][j] - leftrec[i][j] + 1);
				maxarea = max(area, maxarea);
			}
		}
		cout << maxarea << endl;
		
	}
	return 0;
	
}