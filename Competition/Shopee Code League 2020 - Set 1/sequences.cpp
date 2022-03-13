/*
f(i, j) = Ai * j^2 + Bi for i <= j <= Ci

f(a1, b1) + f(a2, b2) + ... + f(aM, bM) % K == 0
*/


#include <iostream>
#include <vector>

using namespace std;

constexpr long long MOD = 1000000007;

vector<long long> countMod;

long long count(int m, int r, int k) {
    if(m == 0) {
        return 1;
    }

    if(m == 1) {
        return countMod[r];
    }

    if(m % 2 == 1) {
        long long ans = (count(m-1, 0, k) * count(1, 0, k)) % MOD;
        for(int i = 1; i < k; i++) {
            ans += (count(m-1, i, k) * count(1, k-i, k)) % MOD;
        }
        return ans % MOD;
    }

    vector<long long> c(k);
    for(int i = 0; i < k; i++) {
        c[i] = count(m/2, i, k);
    }

    long long ans = (c[0] * c[0]) % MOD;
    for(int i = 1; i < k; i++) {
        ans += (c[i] * c[k-i]) % MOD;
    }
    return ans % MOD;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    countMod.assign(k, 0);

    long long a, b, c;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        for(int j = 1; j <= k && j <= c; j++) {
            int remainder = (a * j * j + b) % k;
            int repeated = (c-j) / k + 1;

            countMod[remainder] += repeated;
        }
    }

    for(int i = 0; i < k; i++) {
        countMod[i] %= MOD;
    }

    cout << count(m, 0, k) << endl;

    return 0;
}
