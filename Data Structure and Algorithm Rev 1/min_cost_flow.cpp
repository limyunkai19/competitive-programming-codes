// My implementation of Min Cost Max Flow algorithm with SPFA
// Solve Kattis problem: https://open.kattis.com/problems/mincostmaxflow
// Reference:
//   https://cp-algorithms.com/graph/min_cost_flow.html
//   https://github.com/limyunkai19/competitive-programming-codes/blob/master/Data%20Structure%20and%20Algorithm/MinCostFlow_SPFA.cpp
// Details:
//  - idea is send to a augmented flow with cheapest cost each time
//  - negative flow will exist as sending a reverse flow will cancel out the effect, hence negative cost
//  - ignore the case of negative cycle in SPFA algorithm

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
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    MinCostFlow minCostFlowProblem(n);

    while(m--) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;

        minCostFlowProblem.addEdge(u, v, c, w, true);
    }

    pair<int, int> ans = minCostFlowProblem.getMinCostFlow(s, t);

    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}
