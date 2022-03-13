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

class OrderedMultiSet {
    int sz = 0;
    map<int, int> idx;
    shared_ptr<FenwickTree> fenwickTree;

public:
    OrderedMultiSet(vector<int> value) {
        sort(value.begin(), value.end());
        value.resize(unique(value.begin(), value.end()) - value.begin());

        fenwickTree = make_shared<FenwickTree>(value.size());
        for(int i = 0; i < value.size(); i++) {
            idx[value[i]] = i+1;
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
    int n, k;
    cin >> n >> k;

    int pre = 0;
    vector<int> a(n), sum(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
        sum[i] = pre + a[i];
        pre = sum[i];
    }

    OrderedMultiSet orderedMultiSet(sum);
    for(const int& s : sum) {
        orderedMultiSet.update(s, 1);
    }

    int ans = 0;
    pre = 0;
    for(const int& s : sum) {
        ans += orderedMultiSet.countGreaterOrEqual(pre);
        orderedMultiSet.update(s, -1);
        pre = s;
    }

    cout << ans << endl;

    return 0;
}
