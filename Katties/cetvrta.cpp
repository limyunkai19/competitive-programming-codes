#include <iostream>

using namespace std;

int main(){
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout << 2*(max(x1, max(x2, x3)) + min(x1, min(x2, x3))) - x1 - x2 - x3 <<
    " "  << 2*(max(y1, max(y2, y3)) + min(y1, min(y2, y3))) - y1 - y2 - y3 << endl;

    return 0;
}