// link: https://csacademy.com/ieeextreme-practice/task/language-learning/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    constexpr int mod = 1'000'000'007;

    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> dp(n+1, 0);
        unordered_map<string, int> preIdx;

        for(int i = 1; i <= n; i++) {
            string s; cin >> s;

            // recurrence
            if(!preIdx.count(s)) {
                dp[i] = 1; // start a string
            }

            if(i-k-1 >= 0) {
                dp[i] += dp[i-k-1];
            }

            // duplication
            if(preIdx[s]-k-1 >= 0) {
                dp[i] -= dp[preIdx[s]-k-1];
            }

            // record
            preIdx[s] = i;
            dp[i] = ((dp[i] + dp[i-1]) % mod + mod) % mod;
        }

        cout << dp.back() << "\n";
    }

    return 0;
}
