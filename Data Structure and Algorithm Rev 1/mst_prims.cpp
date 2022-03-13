// My implementation of Prim's algorithm
// Solve Kattis problem: https://open.kattis.com/problems/cats

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// this assume the graph is connected
// if it is not, change the code to use a for loop to find spanning forest
int PrimsMST(vector<vector<pair<int, int>>> graph) {
    int mst = 0;
    vector<bool> included(graph.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.emplace(0, 0);
    while(!pq.empty()) {
        auto [e, u] = pq.top(); pq.pop();
        if(included[u]) {
            continue;
        }

        included[u] = true;
        mst += e;

        for(const auto& [v, w] : graph[u]) {
            if(!included[v]) {
                pq.emplace(w, v);
            }
        }
    }

    return mst;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int k, n; cin >> k >> n;
        vector<vector<pair<int, int>>> graph(n);

        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        int mst = PrimsMST(graph);
        if(mst + n <= k)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
