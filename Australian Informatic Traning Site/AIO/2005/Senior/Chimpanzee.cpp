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
    freopen("chimpin.txt", "r", stdin);
    freopen("chimpout.txt", "w", stdout);

    int x, y, side, det, layer;
    cin >> x >> y;
    if(x == 0 && y == 0){
        cout << 0 << endl;
        return 0;
    }
    if(abs(x) == abs(y)){
        if(x > 0 && y > 0){
            side = 1;
        }
        else if(y > 0 && x < 0){
            side = 2;
        }
        else if(y < 0 && x < 0){
            side = 3;
        }
        else{
            side = 4;
        }
        layer = abs(x);
        det = 2*abs(x)-1;
    }
    else if(abs(x) > abs(y)){ // layer is abs(x)
        if(x > 0){
            side = 1;
            det = y - (-abs(x) + 1);
        }
        else{
            side = 3;
            det = abs(x) - 1 - y;
        }
        layer = abs(x);
    }
    else{   //layer is abs(y)
        if(y > 0){
            side = 2;
            det = abs(y) - 1 - x;
        }
        else{
            side = 4;
            det = x - (-abs(y) + 1);
        }
        layer = abs(y);
    }
    int ans = (2*layer-1)*(2*layer-1);
    side--; ans += side*(2*layer);
    ans += det;
    cout << ans << endl;

    return 0;
}
