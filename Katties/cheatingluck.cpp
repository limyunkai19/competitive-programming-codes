#include <iostream>
#include <cstring>

using namespace std;

int sum, dp[2010][52][52];

int max_win(int coin, int n, int k){
    if(dp[coin][n][k] != -1)
        return dp[coin][n][k];
    if(n == 0)
        return dp[coin][n][k] = coin;
    if(n == k)
        // sure win, bet all
        return dp[coin][n][k] = max_win(min(sum, coin*2), n-1, k-1);
    if(k == 0)
        // sure lose, dont bet
        return dp[coin][n][k] = coin;
    if(coin == sum)
        // already win
        return dp[coin][n][k] = coin;
    if(coin == 0 || coin == 1)
        // cant bet anymore
        return dp[coin][n][k] = coin;

    int ans = coin, a = coin, b = sum-coin, pre = 0;

    // try bet from 0 to min(a, b);      v dont use this version
    for(int bet = 0; bet <= min(a, b) && false; bet++){
        // maybe win, maybe lose
        // need choose worst case
        //                           win                          lose
        int now = min(max_win(coin+bet, n-1, k-1), max_win(coin-bet, n-1, k));
        //               ^ strictly increasing      ^ monotonic decreasing      [more obervation after TLE]
        // find intersection point, can use binary search                       [more obervation after TLE]

        // max_win(x, ...) >= x, max_win(x+1, ... ) >= max_win(x, ...)          [more obervation after TLE]

        ans = max(ans, now);
    }


    int hi = min(a, b), lo = 0;
    while(hi > lo+1){
        int bet = (hi+lo)/2;

        int  win = max_win(coin+bet, n-1, k-1);
        int lose = max_win(coin-bet, n-1, k);

        if(win == lose){
            // found
            return dp[coin][n][k] = win;
        }
        else if(win > lose){
            hi = bet;
        }
        else{
            lo = bet;
        }
    }

    hi = min(max_win(coin+hi, n-1, k-1), max_win(coin-hi, n-1, k));
    lo = min(max_win(coin+lo, n-1, k-1), max_win(coin-lo, n-1, k));

    ans = max(ans, max(hi, lo));

    return dp[coin][n][k] = ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    int a, b, n, k;
    cin >> a >> b >> n >> k;

    sum = a+b;

    cout << max_win(a, n, k) << endl;

    return 0;
}