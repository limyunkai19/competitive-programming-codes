#include <iostream>
#include <vector>

using namespace std;

inline pair<int, int> decode(const int& idx, int col) {
    return pair<int, int> (idx / col, idx % col);
}

inline int encode(const int& r, const int& c, const int& col) {
    return r * col + c;
}

inline void moveSingleStep(int& x, int& dx, const int& n) {
    x += dx;
    if(x < 0 || x >= n) {
        x -= 2 * dx;
        dx = -dx;
    }
}

inline int bounce(int x, int dx, const int& n) {
    if(n == 1) {
        return 0;
    }

    moveSingleStep(x, dx, n);
    moveSingleStep(x, dx, n);

    return x;
}

// constexpr
constexpr int LIMIT = 61;
constexpr long long MOD = 1000000007;
constexpr int dr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
constexpr int dc[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    int n, nn;
    cin >> n;
    nn = n*n;

    vector<vector<vector<long long>>> steps(nn, vector<vector<long long>>(nn, vector<long long>(LIMIT)));

    // compute base case where steps = 1
    for(int u = 0; u < steps.size(); u++) {
        auto [ur, uc] = decode(u, n);

        for(int i = 0; i < 8; i++) {
            int vr = bounce(ur, dr[i], n);
            int vc = bounce(uc, dc[i], n);

            steps[u][encode(vr, vc, n)][0] = 1;
        }
    }

    // compute for steps = 2, 4, 8, 16, ..., 2^LIMIT
    for(int bit = 1; bit < LIMIT; bit++) {
        for(int u = 0; u < nn; u++) for(int v = 0; v < nn; v++) for(int k = 0; k < nn; k++) {
            steps[u][v][bit] += steps[u][k][bit-1] * steps[k][v][bit-1];
            steps[u][v][bit] %= MOD;
        }
    }

    int ur, uc, vr, vc;
    long long k;

    cin >> ur >> uc;
    while(cin >> vr >> vc >> k) {
        vector<long long> ans1, ans(nn, 0);
        ans[encode(ur, uc, n)] = 1;

        // binary lifting technique
        for(int bit = 0; bit < LIMIT; bit++) {
            if(k & (1LL<<bit)) {
                ans1.assign(nn, 0);
                for(int u = 0; u < nn; u++) for(int v = 0; v < nn; v++) {
                    ans1[v] += ans[u] * steps[u][v][bit];
                    ans1[v] %= MOD;
                }
                ans = ans1;
            }
        }

        cout << ans[encode(vr, vc, n)] << '\n';
    }
}
