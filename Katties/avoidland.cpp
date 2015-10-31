#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int x[1000100], y[1000100];

int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    for(int i = 1; i <= n; i++){
        ans += abs(x[i-1]-i)+abs(y[i-1]-i);
    }
    cout << ans << endl;
    return 0;
}