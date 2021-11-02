// link: https://csacademy.com/ieeextreme-practice/task/appointment/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<ii, int>> window(n);
        for(int i = 0; i < n; i++) {
            window[i].second = i+1;
            cin >> window[i].first.first >> window[i].first.second;
        }
        sort(window.rbegin(), window.rend());

        vector<int> ans;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        for(int i = 1; i <= n; i++) {
            while(window.size() > 0 && window.back().first.first <= i) {
                pq.emplace(window.back().first.second, window.back().second);
                window.pop_back();
            }

            if(pq.empty()) {
                ans.clear();
                break;
            }

            const auto [e, idx] = pq.top(); pq.pop();
            if(i > e) {
                ans.clear();
                break;
            }
            ans.push_back(idx);
        }

        if(ans.size() == 0) {
            cout << "impossible\n";
        }
        else {
            for(const int& p : ans) {
                cout << p << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
