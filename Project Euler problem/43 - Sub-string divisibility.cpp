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
    freopen("out.txt", "w", stdout);
    //int comp[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    int dig[10], prime[7] = {1, 2, 3, 5, 7, 11, 13}, a;
    long long sum = 0, b;
    bool sol;
    for(int i = 0; i < 10; i++){
        dig[i] = i;
    }
    do{
        sol = true;
        a = dig[9] + dig[8]*10 + dig[7]*100;
        cout << a << endl;
        if(a % 17 != 0){
            sol = false;
        }
        for(int i = 6; i >= 1; i--){
            a /= 10;
            a += dig[i]*100;
            if(a%prime[i] != 0){
                sol = false;
            }
            cout << a << endl;
        }
        cout << endl;
        if(sol == true){
            b = 0;
            for(int i = 0; i < 10; i++){
                b *= 10;
                b += dig[i];
            }
            cout << b << endl;
            sum += b;
        }
    }
    while(next_permutation(dig, dig+10));
    cout << sum << endl;
    return 0;
}
