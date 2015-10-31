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
    char a;
    const int d = 131071;
    int num = 0;
    while(cin >> a){
        if(a == '#'){
            if(num%d == 0){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            num = 0;
        }
        if(a == '1'){
            num = num*2 + 1;
            num %= d;
        }
        else{
            num *= 2;
            num %= d;
        }
    }
    return 0;
}
