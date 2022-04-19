#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef pair<long long, long long> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long n, m, speed;
    cin >> n >> m >> speed;

    int cur = 0, pre = 1;
    long long preTime = 0;
    vector<long long> dp[2];
    dp[0].assign(n, 0);
    dp[1].assign(n, 0);
    while(m--) {
        long long city, coin, t;
        cin >> city >> coin >> t;
        city--;

        long long range = (t-preTime)*speed;
        // monotonic queue
        deque<ii> dq;

        long long pqR = -1;
        for(int i = 0; i < n; i++) {
            long long l = i - range, r = min(i + range, n-1);
            while(pqR < r) {
                ++pqR;
                while(dq.size() > 0 && dq.back().first <= dp[pre][pqR]) {
                    dq.pop_back();
                }
                dq.emplace_back(dp[pre][pqR], pqR);
            }
            while(dq.front().second < l) {
                dq.pop_front();
            }

            dp[cur][i] = coin - abs(city-i) + dq.front().first;
        }

        cur = !cur;
        pre = !pre;
        preTime = t;
    }

    long long ans = dp[pre][0];
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[pre][i]);
    }

    cout << ans << endl;

    return 0;
}
