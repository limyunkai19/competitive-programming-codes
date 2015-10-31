#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int lastdig[10010];

int main()
{
    lastdig[0] = 1;
    int dig;
    for(int i = 1; i < 10003; i++){
        dig = lastdig[i-1]*i;
        while(dig%10 == 0){
            dig /= 10;
        }
        lastdig[i] = dig%100000;
        //cout << lastdig[i] << endl;
    }

    int n;
    while(cin >> n){
        printf("%5d -> %d\n", n, lastdig[n]%10);
    }

    return 0;
}
