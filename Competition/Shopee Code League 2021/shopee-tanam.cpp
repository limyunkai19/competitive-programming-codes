/*
dynamic programming with space saving trick
O(nm) time with O(1) memory
*/

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int row, col;
        cin >> row >> col;

        long long left, right;
        for(int r = 0; r < row; r++) {
            long long x, sum = 0, maxi = 0, mini = 0;
            for(int c = 0; c < col; c++) {
                cin >> x;
                sum += x;
                maxi = max(maxi, sum);
                mini = min(mini, sum);
            }

            if(r == 0) {
                left = maxi;
                right = sum;
            }
            else {
                long long newLeft = max(left + maxi, right + sum);
                long long newRight = max(right + (sum - mini), left + sum);
                left = newLeft;
                right = newRight;
            }
        }

        cout << max(left, right) << endl;
    }
}
