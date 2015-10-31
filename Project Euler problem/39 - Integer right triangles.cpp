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
    int p[1005], c;
    memset(p, 0, sizeof p);
    for(int a = 1; a <= 1000; a++){
        for(int b = a; b <= 1000; b++){
            c = sqrt(a*a + b*b);
            if(c*c == a*a + b*b && a + b + c <= 1000){
                p[a + b + c]++;
            }
        }
    }
    int max_i = 0, m = 0;
    for(int i = 0; i <= 1000; i++){
        if(p[i] > m){
            m = p[i];
            max_i = i;
        }
    }
    cout << max_i << ' ' << p[max_i] << endl;

    return 0;
}
