// min cost flow problem
// O(n) vertex, O(n^2) edge
// time complexity for min cost flow algorithm (SPFA) is O(v^2 e^2)
// total time complexity is O(n^6) but in practical should be much more lesser

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MinCostFlow {
    constexpr static long long INF = 1LL<<62;

    struct Edge {
        int u, v;
        long long cap, cost;

        Edge(int u, int v, long long cap, long long cost)
            : u(u), v(v), cap(cap), cost(cost) {}
    };


    int n;
    vector<Edge> e;
    vector<vector<int>> graph;

    // ignore negative cycle
    bool SPFA(int s, int t, vector<int>& parent, vector<long long>& dist) {
        parent.assign(n, -1);
        dist.assign(n, INF);            dist[s] = 0;
        vector<bool> inqueue(n, false); inqueue[s] = true;
        queue<int> q;                   q.push(s);

        while(!q.empty()) {
            int u = q.front(); q.pop(); inqueue[u] = false;

            for(const int& eIdx : graph[u]) {
                int v = e[eIdx].v, w = e[eIdx].cost, cap = e[eIdx].cap;

                if(cap > 0 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = eIdx;

                    if(!inqueue[v]) {
                        q.push(v);
                        inqueue[v] = true;
                    }
                }
            }
        }

        return dist[t] != INF;
    }

public:
    // 0-based indexing
    MinCostFlow(int n) : n(n) {
        graph.assign(n, vector<int>());
    }

    void addEdge(int u, int v, long long cap, long long cost, bool directed) {
        graph[u].push_back(e.size());
        e.push_back(Edge(u, v, cap, cost));

        graph[v].push_back(e.size());
        e.push_back(Edge(v, u, 0, -cost));

        if(!directed)
            addEdge(v, u, cap, cost, true);
    }

    // return (flow, cost)
    pair<long long, long long> getMinCostFlow(int s, int t) {
        long long flow = 0, cost = 0;

        vector<int> parent;
        vector<long long> dist;
        while(SPFA(s, t, parent, dist)) {
            // send flow
            long long f = (1LL<<62);
            for(int eIdx = parent[t]; eIdx != -1; eIdx = parent[e[eIdx].u]) {
                f = min(e[eIdx].cap, f);
            }

            for(int eIdx = parent[t]; eIdx != -1; eIdx = parent[e[eIdx].u]) {
                cost += f * e[eIdx].cost;
                e[eIdx].cap -= f;
                e[eIdx^1].cap += f;
            }

            flow += f;
        }

        return make_pair(flow, cost);
    }


};

int main() {
    int n, d, e;
    cin >> n >> d >> e;

    const int INVALID = 100 * n;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INVALID));
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = dist[v][u] = 1;
    }

    // O(n^3) floyd-warshall APSP
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int source = 0, sink = n+1;
    MinCostFlow minCostFlowProblem(sink+1);
    for(int i = 0; i < d; i++) { // add edge for each warehouse
        int stock, cost, u;
        cin >> stock >> cost >> u;

        minCostFlowProblem.addEdge(source, u, stock, 0, true);
        for(int v = 1; v <= n; v++) { // add edge for delivery to each city
            if(u != v && dist[u][v] != INVALID) {
                minCostFlowProblem.addEdge(u, v, stock, cost * dist[u][v], true);
            }
        }
    }

    // gather all consumer order for a total sink capacity
    vector<int> sinkCap(n+1, 0);

    int m;
    cin >> m;
    while(m--) {
        int w, v;
        cin >> w >> v;

        sinkCap[v] += w;
    }

    // add edge for sink
    for(int i = 1; i <= n; i++) {
        minCostFlowProblem.addEdge(i, sink, sinkCap[i], 0, true);
    }

    pair<int, int> ans = minCostFlowProblem.getMinCostFlow(source, sink);

    cout << ans.second << endl;

    return 0;
}
