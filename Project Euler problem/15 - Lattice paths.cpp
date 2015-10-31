#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
    long long fill[25][25];
    int n = 20;
    n++;
    memset(fill, 0, sizeof fill);
    fill[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            fill[i-j+1][j] += fill[i-j][j] + fill[i-j+1][j-1];
            //printf("(%d, %d) = %d\n", i-j+1, j, fill[i-j+1][j]);
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; i+j <= n; j++){
            fill[n-j][i+j] += fill[n-j-1][i+j] + fill[n-j][i+j-1];
        }
    }
    /*for(int i = 1; i <= n; i++){
        for(int j= 1; j <= n; j++)
            cout << fill[i][j] << " ";
        cout << endl;
    }*/
    cout << fill[n][n] << endl;
    return 0;
}
