#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a, b = 0;
    cin >> a;
    while(a > 0){
        b *= 2;
        b += a%2;
        a /= 2;
    }
    cout << b << endl;
}