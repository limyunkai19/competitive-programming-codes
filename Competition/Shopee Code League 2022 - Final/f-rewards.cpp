#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> project(n);
    for(int i = 0; i < n; i++) {
        cin >> project[i].first >> project[i].second;
    }

    long long ans = 0;
    priority_queue<int> pq;
    sort(project.rbegin(), project.rend());
    for(int year = project[0].first, pIdx = 0; year >= 1; year--) {
        // push all project with due date longer than or euqal to year into pq
        while(pIdx < project.size() && year <= project[pIdx].first) {
            pq.emplace(project[pIdx++].second);
        }

        if(pq.size() == 0) {
            continue;
        }

        ans += pq.top(); pq.pop();
    }

    cout << ans << endl;

    return 0;
}
