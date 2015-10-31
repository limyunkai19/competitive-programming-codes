#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool used[10];

bool penta(int a, int b, int c){
    memset(used, false, sizeof used);
    used[0] = true;
    while(a > 0){
        if(used[a%10]){
            return false;
        }
        else{
            used[a%10] = true;
        }
        a /= 10;
    }

    while(b > 0){
        if(used[b%10]){
            return false;
        }
        else{
            used[b%10] = true;
        }
        b /= 10;
    }

    while(c > 0){
        if(used[c%10]){
            return false;
        }
        else{
            used[c%10] = true;
        }
        c /= 10;
    }

    for(int i = 0; i < 10; i++){
        if(!used[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    int sum = 0;
    for(int i = 100; i < 100000; i++){
        for(int j = 1; j*j < i; j++){
            if(i%j == 0){
                if(penta(j, i/j, i)){
                    //cout << j << " x " << i/j << " = " << i << endl;
                    sum += i;
                    break;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
