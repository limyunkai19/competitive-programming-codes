#include <iostream>
#include <vector>
#include <unordered_map>
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
                cost += e[eIdx].cost;
                e[eIdx].cap -= f;
                e[eIdx^1].cap += f;
            }

            flow += f;
        }

        return make_pair(flow, cost);
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> idx;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        idx[s] = i;
    }

    vector<vector<int>> debt(n, vector<int>(n, 0));
    while(m--) {
        int k;
        cin >> k >> s;
        int boss = idx[s];

        while(k--) {
            int money, l;
            cin >> money >> l;
            for(int _ = 0; _ < l; _++) {
                cin >> s;
                debt[idx[s]][boss] += money / l;
            }
        }
    }

    MinCostFlow mcf(n+2);
    int source = n, sink = n+1, INF = 1<<30;

    for(int i = 0; i < n; i++) {
        int in = 0, out = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }

            in += debt[j][i];
            out += debt[i][j];
        }

        if(in == out) continue;
        if(in > out) {
            mcf.addEdge(i, sink, in-out, 0, true);
        }
        else {
            mcf.addEdge(source, i, out-in, 0, true);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            mcf.addEdge(i, j, INF, 1, false);
        }
    }

    auto [flow, cost] = mcf.getMinCostFlow(source, sink);

    cout << flow << ' ' << cost << endl;

    return 0;
}
