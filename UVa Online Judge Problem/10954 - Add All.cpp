#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
	priority_queue<int, vector<int>, greater<int> > pq;
	int n, ans, sum, x, y;
	while(cin >> n && n != 0){
		while(n--){
			cin >> x;
			pq.push(x);
		}
		ans = 0;
		while(pq.size() != 1){
			x = pq.top(); pq.pop(); 
			y = pq.top(); pq.pop();
			ans += x+y;
			pq.push(x+y);
		}
		pq.pop();
		cout << ans << endl;
	}
	
	
	return 0;
}