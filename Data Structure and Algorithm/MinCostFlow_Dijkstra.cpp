// my implementation of min cost max flow with djikstra (with vertex potential)
// solve kattis problem: https://open.kattis.com/problems/mincostmaxflow

// not yet tested on starting negative edge

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

struct Edge{
    int u, v;
    long long cap, cost;

    Edge(int _u, int _v, long long _cap, long long _cost){
        u = _u; v = _v; cap = _cap; cost = _cost;
    }
};

struct MinCostFlow{
    int n, s, t;
    long long flow, cost;
    vector<vector<int> > graph;
    vector<Edge> e;
    vector<long long> dist, potential;
    vector<int> parent;
    bool negativeCost;

    MinCostFlow(int _n){
        // 0-based indexing
        n = _n;
        graph.assign(n, vector<int> ());
        negativeCost = false;
    }

    void addEdge(int u, int v, long long cap, long long cost, bool directed){
        if(cost < 0)
            negativeCost = true;

        graph[u].push_back(e.size());
        e.push_back(Edge(u, v, cap, cost));

        graph[v].push_back(e.size());
        e.push_back(Edge(v, u, 0, -cost));

        if(!directed)
            addEdge(v, u, cap, cost, true);
    }

    pair<long long, long long> getMinCostFlow(int _s, int _t){
        s = _s; t = _t;
        flow = 0, cost = 0;

        potential.assign(n, 0);
        if(negativeCost){
            // run Bellman-Ford to find starting potential
            dist.assign(n, 1LL<<62);
            for(int i = 0, relax = false; i < n && relax; i++, relax = false){
                for(int u = 0; u < n; u++){
                    for(int k = 0; k < graph[u].size(); k++){
                        int eIdx = graph[u][i];
                        int v = e[eIdx].v, cap = e[eIdx].cap, w = e[eIdx].cost;

                        if(dist[v] > dist[u] + w && cap > 0){
                            dist[v] = dist[u] + w;
                            relax = true;
                        }
                    }
                }
            }

            for(int i = 0; i < n; i++){
                if(dist[i] < (1LL<<62)){
                    potential[i] = dist[i];
                }
            }
        }

        while(dijkstra()){
            flow += sendFlow(t, 1LL<<62);
        }

        return make_pair(flow, cost);
    }

    bool dijkstra(){
        parent.assign(n, -1);
        dist.assign(n, 1LL<<62);
        priority_queue<ii, vector<ii>, greater<ii> > pq;

        dist[s] = 0;
        pq.push(ii(0, s));


        while(!pq.empty()){
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if(d != dist[u]) continue;

            for(int i = 0; i < graph[u].size(); i++){
                int eIdx = graph[u][i];
                int v = e[eIdx].v, cap = e[eIdx].cap;
                int w = e[eIdx].cost + potential[u] - potential[v];

                if(dist[u] + w < dist[v] && cap > 0){
                    dist[v] = dist[u] + w;
                    parent[v] = eIdx;

                    pq.push(ii(dist[v], v));
                }
            }
        }

        // update potential
        for(int i = 0; i < n; i++){
            if(dist[i] < (1LL<<62))
                potential[i] += dist[i];
        }

        return dist[t] != (1LL<<62);
    }

    long long sendFlow(int v, long long curFlow){
        if(parent[v] == -1)
            return curFlow;
        int eIdx = parent[v];
        int u = e[eIdx].u, w = e[eIdx].cost;

        long long f = sendFlow(u, min(curFlow, e[eIdx].cap));

        cost += f*w;
        e[eIdx].cap -= f;
        e[eIdx^1].cap += f;

        return f;
    }
};

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    MinCostFlow minCostFlowProblem(n);

    while(m--){
        int u, v, c, w;
        cin >> u >> v >> c >> w;

        minCostFlowProblem.addEdge(u, v, c, w, true);
    }

    pair<int, int> ans = minCostFlowProblem.getMinCostFlow(s, t);

    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}