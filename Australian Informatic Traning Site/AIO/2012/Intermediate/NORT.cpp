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
    freopen("nortin.txt", "r", stdin);
    freopen("nortout.txt", "w", stdout);

    int w, h;
    cin >> w >> h;
    if(w%2 == 0 || h%2 == 0){
        cout << w*h << endl;
    }
    else{
        cout << w*h-1 << endl;
    }

    return 0;
}
