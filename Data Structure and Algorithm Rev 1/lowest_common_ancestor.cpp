// My LCA implementation
// Solve Kattis problem: https://open.kattis.com/problems/boxes

#include <iostream>
#include <vector>
#include <cmath>

// problem specific
#include <numeric>

using namespace std;

// binary lifting / sparse parent table - O(nlog n) preprocess, O(log n) per query
class BinaryLiftingLCA {
    int logn, root;
    vector<int> depth;
    vector<vector<int>> parent, tree;

    void build(int u, int d = 0, int p = -1) {
        depth[u] = d;
        parent[u][0] = p;
        for(int i = 1; i <= logn && parent[u][i-1] >= 0; i++) {
            parent[u][i] = parent[parent[u][i-1]][i-1];
        }

        for(const int& v : tree[u]) {
            if(v == p) continue;
            build(v, d+1, u);
        }
    }

    int getParent(int u, int k) {
        for(int i = 0; k > 0 && u >= 0; i++, k >>= 1) {
            if(k & 1) {
                u = parent[u][i];
            }
        }
        return u;
    }

public:
    BinaryLiftingLCA(vector<vector<int>> tree, int root = 0) : tree(tree), root(root) {
        logn = (int)log2(tree.size()) + 1;
        parent.assign(tree.size(), vector<int>(logn + 1, -1));
        depth.resize(tree.size());

        build(root);
    }

    int GetLCA(int x, int y) {
        if(depth[x] > depth[y]) {
            swap(x, y);
        }

        y = getParent(y, depth[y]-depth[x]);
        if(x == y) {
            return x;
        }

        // now x, y are same depth, find the highest not same parent
        for(int i = logn; i >= 0; i--) {
            if(parent[x][i] != parent[y][i]) {
                x = parent[x][i];
                y = parent[y][i];
            }
        }

        return parent[x][0];
    }
};

// sparse table rmq - O(nlog n) preprocess, O(1) pre query
class SparseTableLCA {

};

void computeSize(int u, vector<int>& size, const vector<vector<int>>& tree) {
    for(const int& v : tree[u]) {
        computeSize(v, size, tree);
        size[u] += size[v];
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> tree(n+1);
    for(int i = 1; i <= n; i++) {
        int p; cin >> p;
        tree[p].push_back(i);
    }

    vector<int> size(n+1, 1);
    computeSize(0, size, tree);
    BinaryLiftingLCA lcaSolver(tree, 0);

    int q; cin >> q;
    vector<int>  boxes(20), include(20);
    while(q--) {
        int k; cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> boxes[i];
            include[i] = size[boxes[i]];
        }

        for(int i = 0; i < k; i++) {
            for(int j = i + 1; j < k; j++) {
                int lca = lcaSolver.GetLCA(boxes[i], boxes[j]);
                if(lca == boxes[i])
                    include[j] = 0;
                if(lca == boxes[j])
                    include[i] = 0;
            }
        }

        cout << accumulate(include.begin(), include.begin() + k, 0) << '\n';
    }
}
