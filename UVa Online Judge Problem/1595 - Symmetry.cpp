#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int reflex(int x, int mid){
	if(x > mid){
		return mid-(x-mid);
	}
	else if(x < mid){
		return mid+(mid-x);
	}
	
	return x;
}

int main() {
	int minx, maxx, x, y, n, midx, t, ans;
	set<ii> points;
	vector<ii> pointv;
	
	cin >> t;
	while(t--){
		minx = 2000000;
		maxx = -2000000;
		points.clear();
		pointv.clear();
		ans = 0;
		cin >> n;
		while(n--){
			cin >> x >> y;
			x *= 2; y *= 2;
			minx = min(minx, x);
			maxx = max(maxx, x);
			points.insert(ii(x, y));
			pointv.push_back(ii(x, y));
		}
		midx = (minx+maxx)/2;
		for(int i = 0; i < pointv.size(); i++){
			x = pointv[i].first;
			y = pointv[i].second;
			x = reflex(x, midx);
			if(points.count(ii(x, y)) != 1){
				cout << "NO" << endl;
				ans = 1;
				break;
			}
		}
		if(ans == 0){
			cout << "YES" << endl;
		}
	}
	return 0;
}