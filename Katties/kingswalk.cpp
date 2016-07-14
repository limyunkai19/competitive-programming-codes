#include <iostream>
#include <cstdio>

#define mod  5318008

using namespace std;

typedef pair<int, int> ii;

int dp[5050][5050], n;

inline int abs(int x){
    if(x < 0) return -x;
    return x;
}

int ways(int r1, int c1, int r2, int c2){
    int rdiff = abs(r1-r2), cdiff = abs(c1-c2);
    if(rdiff < cdiff)
        return ways(c1, r1, c2, r2);
    if(r2 < r1)
        return ways(r2, c2, r1, c1);

    dp[r1-1][c1] = 1;
    dp[r1-1][c1-1] = 0;
    dp[r1-1][c1+1] = 0;
    for(int row = r1, cols = c1, cole = c1; row <= r2; row++, cols--, cole++){
        dp[row][max(cols-1, 0)] = 0;
        dp[row][min(cole+1, n+1)] = 0;
        dp[row][max(cols-2, 0)] = 0;
        dp[row][min(cole+2, n+2)] = 0;

        for(int col = max(cols, 1); col <= min(cole, n); col++){
            dp[row][col] = (dp[row-1][col-1]+dp[row-1][col]+dp[row-1][col+1])%mod;
        }
    }
    return dp[r2][c2];
}


int main(){
    int t, r1, c1, r2, c2;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> r1 >> c1 >> r2 >> c2;

        cout << ways(r1, c1, r2, c2) << endl;
    }
    return 0;
}