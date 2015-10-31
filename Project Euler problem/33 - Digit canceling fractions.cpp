#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> ii;

ii cancel(int a, int b){
    if(a == b){
        return ii(0, 0);
    }
    if(a%10 == 0 || b%10 == 0){
        return ii(0, 0);
    }
    int a_1 = a/10, a_2 = a%10;
    int b_1 = b/10, b_2 = b%10;
    if(a_1 == b_2 && a_2 == b_1){
        return ii(0, 0);
    }
    if(a_1 == b_1){
        return ii(a_2, b_2);
    }
    if(a_1 == b_2){
        return ii(a_2, b_1);
    }
    if(a_2 == b_1){
        return ii(a_1, b_2);
    }
    if(a_2 == b_2){
        return ii(a_1, b_1);
    }
    return ii(0, 0);
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

int main()
{
    ii t;
    for(int a = 10; a <= 99; a++){
        for(int b = a+1; b <= 99; b++){
            t = cancel(a, b);
            if(t.first != 0 && t.second != 0){
                if(t.first/gcd(t.first, t.second) == a/gcd(a, b) && t.second/gcd(t.first, t.second) == b/gcd(a, b)){
                    cout << a << "/" << b << " = " << t.first << "/" << t.second << endl;
                }
            }
        }
    }

    return 0;
}
