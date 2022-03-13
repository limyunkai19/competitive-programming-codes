// https://open.kattis.com/problems/continuousmedian
// Time on Kattis: 0.14 sec
// Alternative directory contains solution with fenwick tree and pbds

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        constexpr int INF = 2000000000;

        maxHeap.push(-INF);
        minHeap.push(INF);

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> x;

            if(x < minHeap.top()) {
                maxHeap.push(x);
            }
            else {
                minHeap.push(x);
            }

            if(i % 2 == 0) {
                // odd
                if(maxHeap.size() > minHeap.size()) {
                    ans += maxHeap.top();
                }
                else {
                    ans += minHeap.top();
                }
            }
            else {
                // even, need to balance first
                if(maxHeap.size() > minHeap.size()) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
                if(minHeap.size() > maxHeap.size()) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }

                ans += (maxHeap.top() + minHeap.top()) / 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
