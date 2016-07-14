#include <iostream>
#include <cstdio>

using namespace std;

int dp[11][110][110];

int solve(int k, int m1, int m2){
    if(m2 == 0 || m2 < m1)
        return 0;

    if(m1 == m2)
        return m1;

    if(dp[k][m1][m2])
        return dp[k][m1][m2];

    // the base case
    if(k == 1){
        return dp[k][m1][m2] = m2+solve(k, m1, m2-1);
    }

    // recurrence relation
    int ans = 1<<30;

    for(int i = m1; i <= m2; i++){
        // try fire at i

        // if break at i, u know target < i, need test i-1, i-2, ..., m1
        // if no break at i, u know target >= i need test i+1, i+2, ..., m2

        // case 1: need i+solve(k-1, m1, i-1)
        // case 2: need i+solve(k, i+1, m2)

        ans = min(ans, i+max(solve(k-1, m1, i-1), solve(k, i+1, m2)));
    }

    return dp[k][m1][m2] = ans;
}

int main(){
    int k, m, n;
    cin >> n;
    while(n--){
        cin >> k >> m;
        cout << solve(k, 1, m) << endl;
    }


    return 0;
}