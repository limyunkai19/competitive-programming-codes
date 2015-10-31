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
    long long fac[23];
    fac[0] = 1;
    for(int i = 1; i < 21; i++){
        fac[i] = i*fac[i-1];
    }
    int n;
    while(cin >> n){
        if(n > 13){
            cout << "Overflow!" << endl;
        }
        else if(n <= 7 && n >= 0){
            cout << "Underflow!" << endl;
        }
        else if(n < 0){
            n *= -1;
            if(n%2 == 0){
                cout << "Underflow!" << endl;
            }
            else{
                cout << "Overflow!" << endl;
            }
        }
        else{
            cout << fac[n] << endl;
        }
    }

    return 0;
}
