#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    double PI = acos(-1), degree, h;
    cin >> h >> degree;
    cout << ceil(h/sin(degree/180*PI)) << endl;

    return 0;
}