#include <iostream>
#include <cmath>

using namespace std;

double Digit_nCk(int n, int a, int b){
    double digit = 0;
    for(int i = b+1; i <= n; i++){
        digit += log10(i);
    }
    for(int i = 1; i <= a; i++){
        digit -= log10(i);
    }
    return floor(digit) + 1;
}

int main()
{
    int n, k, a, b;
    while(cin >> n >> k){
        a = min(n-k, k);
        b = max(n-k, k);
        cout << Digit_nCk(n, a, b) << "\n";
    }
    return 0;
}
