#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool isTri(long long n){
    double k = (-1 + sqrt(1 + 8*n))/2;
    return (abs(k - (long long)(k)) < 0.00001);
}

bool isPen(long long n){
    double k = (1 + sqrt(1 + 24*n))/6;
    return (abs(k - (long long)(k)) < 0.00001);
}

int main()
{
    long long k = 143, hex;
    while(k++){
        hex = k*(2*k - 1);
        if(isTri(hex) && isPen(hex)){
            cout << k << ": " << hex << endl;
            break;
        }
    }

    return 0;
}
