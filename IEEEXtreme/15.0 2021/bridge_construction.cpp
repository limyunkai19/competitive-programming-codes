// link: https://csacademy.com/ieeextreme-practice/task/bridge

#include <iostream>
#include <vector>

using namespace std;

class CentroidSolver {
private:
    int maxInterDist, centroid, minCentroidDist;
    vector<vector<int>> graph;
    vector<pair<int, int>> subtreeDist;

    void dfs(int u, int p) {
        for(const int& v : graph[u]) {
            if(v == p) {
                continue;
            }

            dfs(v, u);
            if(subtreeDist[v].first + 1 > subtreeDist[u].first) {
                subtreeDist[u].second = subtreeDist[u].first;
                subtreeDist[u].first = subtreeDist[v].first + 1;
            }
            else if(subtreeDist[v].first + 1 > subtreeDist[u].second) {
                subtreeDist[u].second = subtreeDist[v].first + 1;
            }
        }

        int interDist = subtreeDist[u].first + subtreeDist[u].second;
        maxInterDist = max(maxInterDist, interDist);
    }

    void findCentroid(int u, int p, int parentDist) {
        int curDist = subtreeDist[u].first + parentDist;
        maxInterDist = max(maxInterDist, curDist);

        if(max(subtreeDist[u].first, parentDist) < minCentroidDist) {
            centroid = u;
            minCentroidDist = max(subtreeDist[u].first, parentDist);
        }

        for(const int& v : graph[u]) {
            if(v == p) continue;

            int distExceptV = parentDist;
            if(subtreeDist[v].first + 1 == subtreeDist[u].first)
                distExceptV = max(distExceptV, subtreeDist[u].second);
            else
                distExceptV = max(distExceptV, subtreeDist[u].first);

            findCentroid(v, u, distExceptV+1);
        }
    }

public:
    CentroidSolver(const vector<vector<int>>& graph) : graph(graph) {
        maxInterDist = 0;
        minCentroidDist = 1<<30;
        subtreeDist.assign(graph.size(), pair<int, int>(0, 0));

        dfs(1, 0);
        findCentroid(1, 0, 0);
    }

    int getCentroid() {
        return centroid;
    }

    int getCentroidDist() {
        return minCentroidDist;
    }

    int getInterDist() {
        return maxInterDist;
    }
};

int main() {
    int t; cin >> t;
    while(t--) {
        int centroidDist = 1, maxInterDist = 0;
        vector<int> vertex(2);
        for(int i = 0; i < 2; i++) {
            int n;
            cin >> n;
            vector<vector<int>> graph(n+1);
            for(int i = 0; i < n-1; i++) {
                int u, v;
                cin >> u >> v;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            CentroidSolver solver(graph);
            vertex[i] = solver.getCentroid();
            centroidDist += solver.getCentroidDist();
            maxInterDist = max(maxInterDist, solver.getInterDist());
        }

        cout << max(maxInterDist, centroidDist) << '\n' << vertex[0] << ' ' << vertex[1] << '\n';
    }

    return 0;
}
