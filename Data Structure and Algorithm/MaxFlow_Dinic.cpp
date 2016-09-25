// my implementation of dinic algorithm
// used array as queue as stl queue seem to have memory leak issue
// solve SPOJ problem: http://www.spoj.com/problems/FASTFLOW/

#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

#define INF     (1<<30)
#define INFLL   (1LL<<60)

using namespace std;

struct MaxFlow{
    int n, s, t;
    vector<vector<int> > graph;
    // can convert to edge list with edge index
    vector<map<int, long long> > cap;
    vector<int> dist, q, now;

    MaxFlow(int _n){
        // 0-based indexing, init(n+1) for 1 based indexing
        n = _n;
        graph.assign(n, vector<int> ());
        // need to change this if too slow
        cap.assign(n, map<int, long long> ());
        q.resize(n+10);
    }

    void addEdge(int u, int v, long long c, bool directed){
        if(cap[u][v] == 0 && cap[v][u] == 0){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cap[u][v] += c;

        if(!directed){
            cap[v][u] += c;
        }
    }

    long long getMaxFlow(int _s, int _t){
        s = _s; t = _t;
        long long flow = 0;
        while(bfsLevelGraph()){
            now.assign(n, 0);
            while(long long f = dfsSendFlow(s, INFLL))
                flow += f;
        }

        return flow;
    }

    bool bfsLevelGraph(){
        dist.assign(n, INF);
        int qs = 0, qe = 0;
        q[qe++] = s;
        dist[s] = 0;

        while(qs < qe){
            int u = q[qs++];
            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i];

                if(dist[v] == INF && cap[u][v] > 0){
                    dist[v] = dist[u]+1;
                    q[qe++] = v;
                }
            }
        }
        return dist[t] != INF;
    }

    long long dfsSendFlow(int u, long long curFlow){
        if(u == t)          return curFlow;
        if(curFlow == 0)    return curFlow;

        for(; now[u] < graph[u].size(); now[u]++){
            int v = graph[u][now[u]];

            if(dist[v] == dist[u] +1 && cap[u][v] > 0){
                // an edge exist in level graph
                long long flowSent = dfsSendFlow(v, min(curFlow, cap[u][v]));

                if(flowSent > 0){
                    cap[u][v] -= flowSent;
                    cap[v][u] += flowSent;

                    return flowSent;
                }
            }
        }

        return 0;
    }
};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    MaxFlow flow_problem(n+1);

    while(m--){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        if(u == v)
            continue;

        flow_problem.addEdge(u, v, c, false);
    }

    printf("%lld\n", flow_problem.getMaxFlow(1, n));

    return 0;
}