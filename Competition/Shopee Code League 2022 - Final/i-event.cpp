#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class DisjointSet {
private:
    int numSets;
    vector<int> parent, rank, setSize;

public:
    DisjointSet(int n) {
        numSets = n;
        parent.assign(n, 0);
        rank.assign(n, 0);
        setSize.assign(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int getParent(int u) {
        if(parent[u] == u) {
            return u;
        }

        // path compression
        return parent[u] = getParent(parent[u]);
    }

    int getSetSize(int u) {
        return setSize[getParent(u)];
    }

    int getNumSets() {
        return numSets;
    }

    void unionSets(int u, int v) {
        int uParent = getParent(u), vParent = getParent(v);
        if(uParent == vParent) {
            return;
        }

        // union by rank
        if(rank[uParent] > rank[vParent]) {
            swap(uParent, vParent);
        }

        parent[uParent] = vParent;

        if(rank[uParent] == rank[vParent]) {
            rank[vParent]++;
        }

        setSize[vParent] += setSize[uParent];
        numSets--;
    }
};

int main() {
    int n, k, m, x, y;
    cin >> n >> k;

    DisjointSet dsu(n+1);
    while(k--) {
        cin >> m;
        if(m == 0) continue;

        cin >> x;
        for(int i = 1; i < m; i++) {
            cin >> y;
            dsu.unionSets(x, y);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dsu.getSetSize(i) << ' ';
    }

    return 0;
}
