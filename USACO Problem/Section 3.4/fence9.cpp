/*
ID: yunkai91
LANG: C++
TASK: fence9
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);

    // picks theorem
    // A = i + b/2 - 1
    // 2A = 2i + b - 2
    // 2i = 2A - b + 2
    // 2i = bxh - b + 2

    int x, y, w, b=0;
    cin >> x >> y >> w;

    //calculate b
    if(x == 0){
        b += y;
    }
    else{
        // m = y/x
        b += gcd(x, y);
    }
    if(x == w){
        b += y;
    }
    else{
        // m = y/x-w
        b += gcd(abs(w-x), y);
    }
    b += w;

    cout << (y*w - b + 2)/2 << endl;

    return 0;
}