#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long ll;

int main()
{
    int n, k, start;
    ll ans;
    while(cin >> n >> k){
        start = n-k+1;
        ans = 1;
        for(int i = n; i >= start; i--){
            ans *= i;
            while(ans%10 == 0){
                ans /= 10;
            }
            ans %= 1000000000;
        }
        printf("%d\n", ans%10);
    }

    return 0;
}
