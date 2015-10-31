/*
ID: yunkai91
LANG: C++
TASK: game1
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[200], dp[200][200];

int optimal(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];
    if(x == y) return dp[x][y] = a[x];
    if(x > y) return dp[x][y] = 0;

    // player1 take x, leaving x+1, y
        // player 2 take x+1 or y
        // player 2 play optimally hence levaing behind is minimum of others;
            int i = a[x]+min(optimal(x+2, y), optimal(x+1, y-1));
    // player1 take y, leaving x, y-1
        // player 2 take x or y-1
        // player 2 play optimally hence leaving behing is minum
            int j = a[y]+min(optimal(x+1, y-1), optimal(x, y-2));

    return dp[x][y] = max(i, j);
}

int main(){
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);

    memset(dp, -1, sizeof dp);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cout << optimal(1, n) << ' ' << min(optimal(2, n), optimal(1, n-1)) <<  endl;

    return 0;
}