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
    double p, q, r, s, t, u, high, low, x, result;
    while(cin >> p >> q >> r >> s >> t >> u){
        high = 1; low = 0;
        while(fabs(high-low) > 1e-8){
            x = (high + low)/2;
            result = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
            if(result > 0){
                low = x;
            }
            else{
                high = x;
            }
        }

        if(result < 1e-5 && result > -1e-5){
            printf("%0.4lf\n", x);
        }
        else{
            printf("No solution\n");
        }
    }
    return 0;
}
