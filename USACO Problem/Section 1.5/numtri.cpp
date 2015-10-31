/*
ID: yunkai91
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <cstdio>

using namespace std;

int tri[1050][1050];

int main(){
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> tri[i][j];
            tri[i][j] += max(tri[i-1][j], tri[i-1][j-1]);
        }
    }

    int ans = tri[n][1];
    for(int i = 2; i <= n; i++){
        ans = max(ans, tri[n][i]);
    }

    cout << ans << endl;

    return 0;
}