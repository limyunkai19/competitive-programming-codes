// link: https://csacademy.com/ieeextreme-practice/task/image-convolution/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    constexpr int LIMIT = 200;

    int t; cin >> t;
    while(t--) {
        int row, col; cin >> row >> col;
        vector<string> image(row);
        for(int i = 0; i < row; i++)
            cin >> image[i];

        int pRow, pCol; cin >> pRow >> pCol;
        vector<bitset<LIMIT>> pattern(pRow), mask(pRow);
        for(int i = 0; i < pRow; i++) {
            string p; cin >> p;
            for(int bit = 0; bit < pCol; bit++) {
                if(p[bit] == '.') {
                    mask[i][bit] = 1;
                }
                if(p[bit] == '#') {
                    mask[i][bit] = 1;
                    pattern[i][bit] = 1;
                }
            }
        }

        int ans = 0;
        vector<vector<bitset<LIMIT>>> match(row, vector<bitset<LIMIT>>(col));
        for(int r = 0; r < row; r++) {
            bitset<LIMIT> imageRowBit;
            for(int c = 0; c < col; c++) {
                // update
                imageRowBit >>= 1;
                if(image[r][c] == '#') {
                    imageRowBit[pCol-1] = 1;
                }

                // test
                if(c+1 >= pCol) {
                    match[r][c][0] = ((imageRowBit ^ pattern[0]) & mask[0]).none();

                    if(r > 0) {
                        for(int i = 1; i < pRow; i++) {
                            if(match[r-1][c][i-1]) {
                                match[r][c][i] = ((imageRowBit ^ pattern[i]) & mask[i]).none();
                            }
                        }
                    }

                    if(match[r][c][pRow-1]) {
                        ans++;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
