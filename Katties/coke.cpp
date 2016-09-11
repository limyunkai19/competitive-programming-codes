#include <iostream>
#include <cstring>

using namespace std;

int dp[160][160][60], sum;

int coin(int x, int five, int ten){
    if(x == 0)
        return 0;
    if(dp[x][five][ten] != -1)
        return dp[x][five][ten];

    if(five == 0 && ten == 0)
        return dp[x][five][ten] = x*8;

    int ans = 1<<30;
    int one = sum - five*5 - ten*10;

    if(five > 1)
        ans = min(ans, coin(x-1, five-2, ten)+2);
    if(five > 0 && one >= 3)
        ans = min(ans, coin(x-1, five-1, ten)+4);
    if(ten > 0 && one >= 3)
        ans = min(ans, coin(x-1, five+1, ten-1)+4);
    if(ten > 0)
        ans = min(ans, coin(x-1, five, ten-1)+1);

    return dp[x][five][ten] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof dp);

        int x, a, b, c;
        cin >> x >> a >> b >> c;

        sum = a+b*5+c*10;

        cout << coin(x, b, c) << endl;
    }

    return 0;
}