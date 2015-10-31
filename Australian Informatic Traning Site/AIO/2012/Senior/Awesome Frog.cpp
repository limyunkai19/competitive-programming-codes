#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    freopen("frogin.txt", "r", stdin);
    freopen("frogout.txt", "w", stdout);

	int n, dist, pad = 0, a;
	int pos[100005], diff[100005];
	scanf("%d %d", &n, &dist);
	pos[0] = 0;
	for(int i = 1; i < n; i++){
		scanf("%d", &a);
		pad += a;
		pos[i] = pad;
		diff[i] = i*dist - pad;
	}
	
	sort(diff, diff+n);
	int shift = -diff[n/2], ans = 0;
	for(int i = 0; i < n; i++){
		ans += abs(pos[i]-shift);
		shift += dist;
	}
	
	cout << ans << endl;

    return 0;
}
