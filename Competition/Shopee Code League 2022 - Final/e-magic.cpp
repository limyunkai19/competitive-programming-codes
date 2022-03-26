#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n; cin >> n;

    for(int i = 1; i < 30; i++) {
        if(n == (1<<i)-1) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
