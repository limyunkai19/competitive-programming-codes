#include <iostream>
#include <vector>

using namespace std;

constexpr long long INF = 1000000000000000000LL;

long long solve(int i, int k, vector<vector<long long>>& dp, const vector<int>& cost) {
    if(k <= 0) {
        return 0;
    }

    if(i >= cost.size()) {
        return INF;
    }

    if(dp[i][k] != -1) {
        return dp[i][k];
    }

    dp[i][k] = min(solve(i+1, k, dp, cost), solve(i+1, k-1, dp, cost) + cost[i]);

    if(i+1 < cost.size()) {
        dp[i][k] = min(dp[i][k], solve(i+2, k-2, dp, cost) + cost[i]);
        dp[i][k] = min(dp[i][k], solve(i+2, k-2, dp, cost) + cost[i+1]);
    }

    return dp[i][k];
}

int main() {
    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        int n, k;
        cin >> n >> k;

        vector<int> cost(n);
        vector<vector<long long>> dp(n, vector<long long>(k+1, -1));

        for(int i = 0; i < n; i++) {
            cin >> cost[i];
        }

        cout << "Case " << tc << ": " << solve(0, k, dp, cost) << "\n";
    }
}
