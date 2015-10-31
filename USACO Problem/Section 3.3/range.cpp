/*
ID: yunkai91
LANG: C++
TASK: range
*/

#include <iostream>
#include <cstdio>

using namespace std;

char grass[300][300];
int up1[300][300], left1[300][300], square[300][300];

int main(){
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grass[i][j];
            if(grass[i][j] == '1'){
                square[i][j] = 1;
                up1[i][j] = up1[i-1][j]+1;
                left1[i][j] = left1[i][j-1]+1;
            }
        }
    }

    for(int sz = 2; sz <= n; sz++){
        int count = 0;
        for(int i = sz; i <= n; i++){
            for(int j = sz; j <= n; j++){
                if(square[i-1][j-1] >= sz-1 && up1[i][j] >= sz && left1[i][j] >= sz){
                    square[i][j] = sz;
                    count++;
                }
            }
        }
        if(count == 0) break;
        cout << sz << ' ' << count << endl;
    }

    return 0;
}
