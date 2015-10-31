#include <iostream>

using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main()
{
    int N = 20;
    unsigned long long int product = 1, gcdz = 1;
    for(int i = 1; i <= N; i++){
        gcdz = gcd(product, i);
        product *= i;
        product /= gcdz;
    }
    cout << product << endl;
    return 0;
}
