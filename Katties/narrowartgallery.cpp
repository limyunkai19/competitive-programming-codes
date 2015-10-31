#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[300][300][2][2], x[300], y[300];

int findmax(int n, int k, int cantakex, int cantakey){
    if(n == -1 && k == 0) return 0;
    if(n == -1) return -10000000;
    if(k > n+1) return -10000000;
    if(k < 0) return -1000000000;
    if(dp[n][k][cantakex][cantakey] != -1) return dp[n][k][cantakex][cantakey];


    int maxans = x[n]+y[n]+findmax(n-1, k, 1, 1);
    if(cantakey == 1){
        maxans = max(maxans, x[n]+findmax(n-1, k-1, 0, 1));
    }
    if(cantakex == 1){
        maxans = max(maxans, y[n]+findmax(n-1, k-1, 1, 0));
    }
    //cout << n << ' ' << k << ' ' << cantakex << ' ' << cantakey << ' ' << maxans << endl;
    return dp[n][k][cantakex][cantakey] = maxans;
}

int main(){
    int n, k;
    while(cin >> n >> k && n != 0){
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        memset(dp, -1, sizeof dp);
        cout << findmax(n-1, k, 1, 1) << endl;
    }

    return 0;
}