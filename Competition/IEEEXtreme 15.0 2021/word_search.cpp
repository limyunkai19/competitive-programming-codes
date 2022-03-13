// link: https://csacademy.com/ieeextreme-practice/task/wordsearch/

#include <iostream>
#include <vector>

using namespace std;

class Matcher {
    int row, col;
    const long long base, mod;
    vector<pair<int, int>> direction{
        {-1, -1}, {-1, 0}, {-1, 1},
         {0, -1},           {0, 1},
         {1, -1},  {1, 0},  {1, 1}
    };
    vector<long long> basePow;
    vector<vector<vector<long long>>> hash;

public:
    Matcher(const vector<string>& grid, long long base, long long mod) : base(base), mod(mod) {
        row = grid.size();
        col = grid[0].size();

        hash.resize(row);
        for(int r = 0; r < row; r++) {
            hash[r].resize(col);
            for(int c = 0; c < col; c++) {
                hash[r][c].resize(direction.size());
                for(int d = 4; d < (int)direction.size(); d++) {
                    const auto& [dr, dc] = direction[d];
                    if(r - dr < 0 || r - dr >= row || c - dc < 0 || c - dc >= col) {
                        hash[r][c][d] = 0;
                    }
                    else {
                        hash[r][c][d] = hash[r-dr][c-dc][d] * base;
                    }

                    hash[r][c][d] = (hash[r][c][d] + grid[r][c]) % mod;
                }
            }
        }

        for(int r = row-1; r >= 0; r--) for(int c = col-1; c >= 0; c--) {
            for(int d = 0; d < 4; d++) {
                const auto& [dr, dc] = direction[d];
                if(r - dr < 0 || r - dr >= row || c - dc < 0 || c - dc >= col) {
                    hash[r][c][d] = 0;
                }
                else {
                    hash[r][c][d] = hash[r-dr][c-dc][d] * base;
                }

                hash[r][c][d] = (hash[r][c][d] + grid[r][c]) % mod;
            }
        }

        basePow.resize(max(row, col) + 1);
        basePow[0] = 1;
        for(int i = 1; i < (int)basePow.size(); i++) {
            basePow[i] = (basePow[i-1] * base) % mod;
        }
    }

    vector<int> Match(string pattern) {
        long long patternHash = pattern[0];
        for(int i = 1; i < (int)pattern.size(); i++) {
            patternHash = (patternHash * base + pattern[i]) % mod;
        }

        for(int r = 0; r < row; r++) for(int c = 0; c < col; c++) {
            for(int d = 0; d < (int)direction.size(); d++) {
                const auto& [dr, dc] = direction[d];
                int endR = r + dr * (pattern.size() - 1);
                int endC = c + dc * (pattern.size() - 1);

                if(endR < 0 || endR >= row || endC < 0 || endC >= col) {
                    continue;
                }

                long long curHash = hash[endR][endC][d];
                if(r - dr >= 0 && r - dr < row && c - dc >= 0 && c - dc < col) {
                    curHash = curHash - (hash[r-dr][c-dc][d] * basePow[pattern.size()]) % mod;
                    curHash = (curHash + mod) % mod;
                }

                if(curHash == patternHash) {
                    return {r, c, endR, endC};
                }
            }
        }

        return {-1};
    }
};

int main() {
    constexpr int base = 131;
    constexpr int mod = 1000000007;

    int r, c, q;
    cin >> r >> c >> q;

    vector<string> grid(r);
    for(int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    Matcher matcher(grid, base, mod);
    while(q--) {
        string s;
        cin >> s;

        auto result = matcher.Match(s);
        if(result[0] == -1) {
            cout << -1 << "\n";
        }
        else {
            cout << result[0] << ' ' << result[1] << ' ' << result[2] << ' ' << result[3] << "\n";
        }
    }

    return 0;
}
