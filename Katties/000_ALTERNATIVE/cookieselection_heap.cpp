// https://open.kattis.com/problems/cookieselection
// Time on Kattis: 0.57 sec

#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    const auto balance = [&] {
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // always let minHeap.size() >= maxHeap.size()
        if(maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    };

    string s;
    while(cin >> s) {
        if(s[0] == '#') {
            cout << minHeap.top() << '\n';
            minHeap.pop();

            balance();
        }
        else {
            int c = stoi(s);
            if(minHeap.size() == 0 || c < minHeap.top()) {
                maxHeap.push(c);
            }
            else {
                minHeap.push(c);
            }

            balance();
        }
    }

    return 0;
}
