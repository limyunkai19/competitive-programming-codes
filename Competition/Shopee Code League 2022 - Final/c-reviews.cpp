#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rollingHashHorizontal(int hashLength, long long base, long long mod, const vector<vector<int>>& a) {
    long long basePowLen = 1;
    for(int i = 0; i < hashLength-1; i++) {
        basePowLen = (basePowLen * base) % mod;
    }

    int row = a.size();
    vector<vector<int>> hash(row);
    for(int i = 0; i < row; i++) {
        // compute hash[i][0] = rollingHash(a[i][0..hashLength])
        hash[i].push_back(0);
        for(int j = 0; j < hashLength; j++) {
            hash[i][0] = (hash[i][0] * base + a[i][j]) % mod;
        }

        // compute hash[i][j] with hash[i][j-1]
        for(int j = hashLength; j < a[i].size(); j++) {
            long long last = (hash[i].back() - a[i][j-hashLength] * basePowLen) % mod;
            last = (last + mod) * base + a[i][j];

            hash[i].push_back(last % mod);
        }
    }

    return hash;
}

vector<vector<int>> transpose(const vector<vector<int>>& a) {
    int row = a.size();
    int col = a[0].size();

    vector<vector<int>> b(col, vector<int>(row));
    for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) {
        b[j][i] = a[i][j];
    }

    return b;
}

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    vector<vector<int>> img1(r1, vector<int>(c1)), img2(r2, vector<int>(c2));
    for(int i = 0; i < r1; i++) for(int j = 0; j < c1; j++) {
        cin >> img1[i][j];
    }
    for(int i = 0; i < r2; i++) for(int j = 0; j < c2; j++) {
        cin >> img2[i][j];
    }

    auto img1Hash = rollingHashHorizontal(c2, 257, 1000000007, img1);
    img1Hash = rollingHashHorizontal(r2, 257, 1000000007, transpose(img1Hash));

    auto img2Hash = rollingHashHorizontal(c2, 257, 1000000007, img2);
    img2Hash = rollingHashHorizontal(r2, 257, 1000000007, transpose(img2Hash));

    int ans = 0;
    for(int i = 0; i < img1Hash.size(); i++) {
        for(int j = 0; j < img1Hash[i].size(); j++) {
            ans += img1Hash[i][j] == img2Hash[0][0];
        }
    }
    cout << ans << endl;

    return 0;
}
