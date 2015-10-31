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
    int n, k, ans, butt;
    while(cin >> n >> k){
        ans = n;
        butt = n;
        while(butt >= k){
            ans += butt/k;
            butt = butt%k + butt/k;
        }
        cout << ans << endl;
    }

    return 0;
}
