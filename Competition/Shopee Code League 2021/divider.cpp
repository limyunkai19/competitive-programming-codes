// O(kn log n) dp with divide and conque optimization

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<long long> dp, dp_cur;
constexpr long long INF = 1LL<<60;

inline long long sum(int i, int j) {
    if(i == 0) return a[j];
    return a[j] - a[i-1];
}

inline long long cost(int i, int j) {
    return sum(i, j) * (j-i+1);
}

void compute(int l, int r, int k1, int k2) {
    if(l > r) return;

    int mid = l + (r-l)/2, best_k;
    dp_cur[mid] = INF;
    for(int k = k1; k <= min(mid, k2); k++) {
        if(k == 0) continue;
        long long curCost = dp[k-1] + cost(k, mid);
        if(curCost < dp_cur[mid]) {
            dp_cur[mid] = curCost;
            best_k = k;
        }
    }

    compute(l, mid-1, k1, best_k);
    compute(mid+1, r, best_k, k2);
}

int main() {
    int n, k;
    cin >> n >> k;

    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            a[i] += a[i-1];
        }
    }

    dp.resize(n);
    dp_cur.resize(n);

    // compute for k = 1
    for(int i = 0; i < n; i++) {
        dp_cur[i] = cost(0, i);
    }

    // iterate k-1 time more to compute k
    for(int i = 0; i < k-1; i++) {
        dp = dp_cur;
        compute(0, n-1, 0, n-1);
    }

    cout << dp_cur[n-1] << endl;

    return 0;
}
