// My Fenwick tree implementation with 3 modes
// Solve SPOJ problem: http://www.spoj.com/problems/HORRIBLE/

#include <vector>
#include <iostream>

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

class FenwickTree_RUPQ {
private:
    FenwickTree tree;

public:
    FenwickTree_RUPQ(int n) : tree(n) {}

    void update(int x, int y, long long v) {
        tree.update(x, v);
        tree.update(y+1, -v);
    }

    long long point_query(int x) {
        return tree.query(x);
    }
};

class FenwickTree_RURQ {
private:
    FenwickTree tree1;
    FenwickTree_RUPQ tree2;

public:
    FenwickTree_RURQ(int n) : tree1(n), tree2(n) {}

    void update(int x, int y, long long v) {
        tree2.update(x, y, v);
        tree1.update(x, v*(x-1));
        tree1.update(y+1, -v*y);
    }

    long long query(int x) {
        return tree2.point_query(x) * x - tree1.query(x);
    }

    long long query(int x, int y) {
        return query(y) - query(x-1);
    }
};

int main() {
    int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        FenwickTree_RURQ tree(n);
        while(q--){
            int type, x, y, val;
            cin >> type;

            if(type == 0){
                cin >> x >> y >> val;
                tree.update(x, y, val);
            }
            else{
                cin >> x >> y;
                cout << tree.query(x, y) << '\n';
            }
        }
    }
}
