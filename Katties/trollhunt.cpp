#include <iostream>

using namespace std;

int main() {
    int b, k, g;
    cin >> b >> k >> g;
    k /= g;

    int days = 0;
    while(b > 1){
        b -= k;
        days++;
    }

    cout << days << endl;
    return 0;
}