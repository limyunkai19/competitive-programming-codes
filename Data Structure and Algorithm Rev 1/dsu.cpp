// My Disjoint Set implementation with union by rank and path compression optimization
// supports size of set query and number of distinct set queries
// Solve Kattis problem: https://open.kattis.com/problems/control

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

    bool isSameSet(int u, int v) {
        return getParent(u) == getParent(v);
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
    int n;
    cin >> n;

    int ans = 0;
    DisjointSet dsu(500010);
    vector<int> ingredient(500010);
    while(n--) {
        int k, sum = 0;
        cin >> k;

        unordered_set<int> parentSet;
        for(int i = 0; i < k; i++) {
            cin >> ingredient[i];

            int parent = dsu.getParent(ingredient[i]);
            if(parentSet.count(parent) == 0) {
                parentSet.insert(parent);
                sum += dsu.getSetSize(ingredient[i]);
            }
        }

        if(sum != k) {
            // skip this recipe
            continue;
        }

        ans++;
        for(int i = 1; i < k; i++) {
            dsu.unionSets(ingredient[0], ingredient[i]);
        }
    }

    cout << ans << endl;
}
