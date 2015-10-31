/*
ID: yunkai91
LANG: C++
TASK: combo
*/

#include <iostream>
#include <cstdio>

using namespace std;

bool match(int a1, int a2, int a3, int b1, int b2, int b3, int n){
    if( (a1-b1+n)%n > 2 && (b1-a1+n)%n > 2 ) return false;
    if( (a2-b2+n)%n > 2 && (b2-a2+n)%n > 2 ) return false;
    if( (a3-b3+n)%n > 2 && (b3-a3+n)%n > 2 ) return false;
    return true;
}

int main(){
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    int n, a1, a2, a3, b1, b2, b3, ans = 0;
    cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    for(int c1 = 1; c1 <= n; c1++) for(int c2 = 1; c2 <= n; c2++) for(int c3 = 1; c3 <= n; c3++)
    {
        if(match(a1, a2, a3, c1, c2, c3, n) || match(b1, b2, b3, c1, c2, c3, n)) ans++;
    }

    cout << ans << endl;

    return 0;
}