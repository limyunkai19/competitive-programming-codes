// My Ordered Multiset implementation with Fenwick tree
// Solve Kattis problem: https://open.kattis.com/problems/continuousmedian
// Time on Kattis: 0.39 sec

// Note: this ordered multiset implemented with fenwick tree is only suitable
//       when the range of input is known beforehand and the range is small
// Time and memory complexity will be based on L = range of input
// Time Complexity: O(log L) for update and count, O(log log L) for findByOrder
// Memory Complexity: O(L)
// Usage:
//  - Initialize an ordered multiset, OrderedMultiset s
//  - Insert one instance of x into the multiset, s.update(x, 1)
//  - Remove one instance of x from the multiset, s.update(x, -1);
//  - Get the i-th (0-based indexing) item from the multiset, s.findByOrder(i)
//  - Count operation, s.countLesser(x), s.countLesserOrEqual(x), s.countGreater(x), s.countGreaterOrEqual(x)
//  - Size of the multiset, s.size()

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>

using namespace std;

// FenwickTree operates on 1-based indexing
class FenwickTree {
private:
    int n;
    vector<long long> bit;

public:
    FenwickTree(int n) : n(n) {
        bit.assign(n+1, 0);
    }

    void update(int x, long long v) {
        for(int i = x; i <= n; i += i&-i) {
            bit[i] += v;
        }
    }

    long long query(int x) {
        long long sum = 0;
        for(int i = x; i > 0; i -= i&-i) {
            sum += bit[i];
        }
        return sum;
    }

    long long query(int x, int y) {
        return query(y) - query(x-1);
    }
};

class OrderedMultiset {
    int sz = 0;
    map<int, int> idx;
    vector<int> revIdx;
    shared_ptr<FenwickTree> fenwickTree;

public:
    OrderedMultiset(vector<int> value) {
        sort(value.begin(), value.end());
        value.resize(unique(value.begin(), value.end()) - value.begin());

        revIdx.resize(value.size()+1);
        fenwickTree = make_shared<FenwickTree>(value.size());
        for(int i = 0; i < value.size(); i++) {
            idx[value[i]] = i+1;
            revIdx[i+1] = value[i];
        }
    }

    bool update(int v, int count) {
        if(idx.count(v) == 0) {
            return false;
        }

        sz += count;
        fenwickTree->update(idx[v], count);
        return true;
    }

    int size() {
        return sz;
    }

    // 0-based indexing
    int findByOrder(int x) {
        if(x >= sz) {
            x = sz-1;
        }

        int lo = 1, hi = idx.size();
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(fenwickTree->query(mid) > x) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }

        return revIdx[lo];
    }

    int countLesser(int x) {
        auto it = idx.lower_bound(x);
        if(it == idx.end()) {
            return sz;
        }
        return fenwickTree->query(it->second - 1);
    }

    int countLesserOrEqual(int x) {
        return countLesser(x+1);
    }

    int countGreater(int x) {
        return sz - countLesserOrEqual(x);
    }

    int countGreaterOrEqual(int x) {
        return sz - countLesser(x);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;
        OrderedMultiset set(a);
        for(int i = 0; i < n; i++) {
            set.update(a[i], 1);
            if(i % 2 == 0) {
                ans += set.findByOrder(i/2);
            }
            else {
                ans += (set.findByOrder(i/2) + set.findByOrder(i/2+1)) / 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
