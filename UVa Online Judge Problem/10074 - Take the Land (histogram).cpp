#include <iostream>
#include <stack>

using namespace std;

bool a[200][200];
int height[200][200];

int main(){
	int m, n, maxarea, area, top;
	stack<int> s;
	while(cin >> m >> n && m != 0){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
				height[i][j] = ((a[i][j] == 0)?(height[i-1][j]+1):0);
			}
		}
		maxarea = 0;
		for(int i = 1; i <= m; i++){
			height[i][0] = -2; height[i][n+1] = -1;
			s.push(0);
			for(int j = 1; j <= n+1; j++){
				//cout << i << ' ' << j << ' ' << height[i][j] << endl;
				if(height[i][j] > height[i][s.top()]){
					s.push(j);
				}
				else if(height[i][j] < height[i][s.top()]){
					while(height[i][j] < height[i][s.top()]){
						top = s.top(); s.pop();
						area = height[i][top]*(j-s.top()-1);
						//cout << area << " = " << height[i][top] << "*(" << j << '-' << s.top() << "-1)" << endl;
						maxarea = max(area, maxarea);
					}
					s.push(j);
				}
				else{
					s.pop();
					s.push(j);
				}
			}
			while(!s.empty()) s.pop();
		}
		cout << maxarea << endl;
	}
	return 0;
}