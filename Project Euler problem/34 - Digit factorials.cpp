#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int fac[11];

int main()
{
    fac[0] = 1;
    for(int i = 1; i < 11; i++){
        fac[i] = i*fac[i-1];
    }
    int a, tem, sum = 0;
    for(int i = 10; i < 1000000; i++){
        a = i;
        tem = 0;
        while(a > 0){
            tem += fac[a%10];
            a /= 10;
        }
        if(tem == i){
            sum += i;
        }
    }
    cout << sum << endl;

    return 0;
}
