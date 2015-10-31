#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    freopen("curryin.txt", "r", stdin);
    freopen("curryout.txt", "w", stdout);

    int c, r, v, x = 0, y = 0, z = 0;
    cin >> c >> r >> v;
    if(v >= r && v >= c){
        while(r+c > v){
            r--; c--; z++;
        }
        x = r; y = c;
    }
    else if(c >= r && c >= v){
        while(r+v > c){
            r--; v--; x++;
        }
        y = v; z = r;
    }
    else{
        while(c+v > r){
            c--; v--; y++;
        }
        x = v; z = c;
    }

    cout << x << " " << y << " " << z << endl;

    return 0;
}
