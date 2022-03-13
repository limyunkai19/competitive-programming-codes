// O(kn^2) dp
// use divide and conquer optimization for O(kn log n)

#include <iostream>
#include <vector>

using namespace std;

int n, maxGroup;
vector<int> a;
vector<vector<long long>> dp;
constexpr long long INF = 1LL<<60;

inline long long sum(int i, int j) {
    if(i == 0) return a[j];
    return a[j] - a[i-1];
}

inline long long cost(int i, int j) {
    return sum(i, j) * (j-i+1);
}

// compute the solution for 0-idx with #group
long long compute(int idx, int group) {
    // invalid
    if(group <= 0 || idx < 0) {
        return INF;
    }

    // dp
    if(dp[idx][group] != -1) {
        return dp[idx][group];
    }

    // base case
    if(group == 1) {
        return dp[idx][group] = cost(0, idx);
    }

    long long ans = INF;
    for(int split = idx; split >= 0; split--) { // try all possible split
        ans = min(ans, compute(split-1, group-1) + cost(split, idx));
    }

    return dp[idx][group] = ans;
}

int main() {
    cin >> n >> maxGroup;

    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            a[i] += a[i-1];
        }
    }

    dp.assign(n, vector<long long>(maxGroup+1, -1));

    cout << compute(n-1, maxGroup) << endl;

    return 0;
}
