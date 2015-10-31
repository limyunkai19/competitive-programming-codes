/*
ID: yunkai91
LANG: C++
TASK: shopping
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int offerproduct[100][5], offernproduct[100][5], offerprice[100];
int buyproduct[5], buynproduct[5], buyprice[5], dp[10][10][10][10][10], productidx[1000];

int main(){
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);

    int s, m, n;
    cin >> s;
    for(int i = 0; i < s; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> offerproduct[i][j] >> offernproduct[i][j];
        }
        cin >> offerprice[i];
    }
    cin >> n;
    memset(productidx, -1, sizeof productidx);
    for(int i = 0; i < n; i++){
        cin >> buyproduct[i] >> buynproduct[i] >> buyprice[i];
        productidx[buyproduct[i]] = i;
    }

    memset(dp, 127, sizeof dp);
    dp[0][0][0][0][0] = 0;

    for(int a = 0; a <= 5; a++)
    for(int b = 0; b <= 5; b++)
    for(int c = 0; c <= 5; c++)
    for(int d = 0; d <= 5; d++)
    for(int e = 0; e <= 5; e++){
        for(int offer = 0; offer < s; offer++){
            // try this offer
            int numberproductidx[10] = {0};
            bool valid = true;
            for(int i = 0; i < 5; i++){
                if(offerproduct[offer][i] == 0) break;
                if(productidx[offerproduct[offer][i]] == -1){
                    valid = false;
                    break;
                }
                else{
                    numberproductidx[productidx[offerproduct[offer][i]]] = offernproduct[offer][i];
                }
            }
            if(!valid) continue;
            if(numberproductidx[0] > a || numberproductidx[1] > b || numberproductidx[2] > c
                || numberproductidx[3] > d || numberproductidx[4] > e) continue;
            dp[a][b][c][d][e] = min(dp[a][b][c][d][e], dp[a- numberproductidx[0]][b- numberproductidx[1]]
                [c- numberproductidx[2]][d- numberproductidx[3]][e- numberproductidx[4]]+offerprice[offer]);
        }
        if(a != 0) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], dp[a-1][b][c][d][e]+buyprice[0]);
        if(b != 0) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], dp[a][b-1][c][d][e]+buyprice[1]);
        if(c != 0) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], dp[a][b][c-1][d][e]+buyprice[2]);
        if(d != 0) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], dp[a][b][c][d-1][e]+buyprice[3]);
        if(e != 0) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], dp[a][b][c][d][e-1]+buyprice[4]);
    }

    cout << dp[buynproduct[0]][buynproduct[1]][buynproduct[2]][buynproduct[3]][buynproduct[4]] << endl;

    return 0;
}

