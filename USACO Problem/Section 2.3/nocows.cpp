/*
ID: yunkai91
LANG: C++
TASK: nocows
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[210][110], dpsum[210][110];

int count(int node, int height);

int countsum(int node, int height){
    if(dpsum[node][height] != -1) return dpsum[node][height];

    int ans = 0;
    for(int i = 0; i <= height; i++){
        ans += count(node, i);
    }
    ans %= 9901;
    return dpsum[node][height] = ans;
}

int count(int node, int height){
    if(dp[node][height] != -1) return dp[node][height];
    if(height == 0) return dp[node][height] = 0;
    if(height == 1 && node != 1) return dp[node][height] = 0;
    if(node == 0) return dp[node][height] = 0;
    if(node == 1 && height == 1) return dp[node][height] = 1;

    int ans = 0;
    for(int i = 1; i < node-1; i++){
        ans += count(i, height-1)*countsum(node-1-i, height-1);
        ans += countsum(i, height-1)*count(node-1-i, height-1);
        ans -= count(i, height-1)*count(node-1-i, height-1);
        ans %= 9901;
    }
    //cout << node << ' ' << height << ' ' << ans << endl;
    ans %= 9901;
    return dp[node][height] = ans;
}

int main(){
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);

    memset(dp, -1, sizeof dp);
    memset(dpsum, -1, sizeof dpsum);
    int n, k;
    cin >> n >> k;
    cout << count(n, k) << endl;

    return 0;
}