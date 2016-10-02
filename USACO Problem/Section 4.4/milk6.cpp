/*
ID: yunkai91
PROG: milk6
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define INF     (1<<30)
#define INFLL   (1LL<<60)

using namespace std;

typedef pair<int, int> ii;

struct MaxFlow{
    int n, s, t;
    vector<vector<ii> > graph;
    vector<long long> cap;
    vector<int> dist, q, now;

    MaxFlow(int _n){
        // 0-based indexing, init(n+1) for 1 based indexing
        n = _n;
        graph.assign(n, vector<ii> ());
        q.resize(n+10);
    }

    void addEdge(int u, int v, long long c, bool directed){
        graph[u].push_back(ii(v, cap.size()));
        cap.push_back(c);
        graph[v].push_back(ii(u, cap.size()));
        cap.push_back(directed?0:c);
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
                int v = graph[u][i].first, e = graph[u][i].second;

                if(dist[v] == INF && cap[e] > 0){
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
            int v = graph[u][now[u]].first, e = graph[u][now[u]].second;

            if(dist[v] == dist[u] +1 && cap[e] > 0){
                // an edge exist in level graph
                long long flowSent = dfsSendFlow(v, min(curFlow, cap[e]));

                if(flowSent > 0){
                    cap[e] -= flowSent;
                    cap[e^1] += flowSent;

                    return flowSent;
                }
            }
        }

        return 0;
    }

    void floodfill(int u, vector<int>& ans, vector<bool>& visited){
        visited[u] = true;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first, e = graph[u][i].second;
            if(!visited[v] && cap[e] > 0)
                floodfill(v, ans, visited);
        }
    }

    void findMinCut(vector<int>&ans){
        vector<bool> visited(n, false);
        floodfill(s, ans, visited);

        for(int u = 0; u < n; u++){
            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i].first, e = graph[u][i].second;

                // only for edge in original graph
                if(e%2 == 0 && visited[u] && !visited[v])
                    ans.push_back(e/2);
            }
        }
    }
};

int main(){
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    const long long MAXM = m+2;

    MaxFlow minCutProblem(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        long long c;
        cin >> u >> v >> c;

        // algorithm 1: used heuristic on number of edge only
        //              the mincut should justify the number of edge (sigma 1 < m)
        minCutProblem.addEdge(u, v, c*MAXM+1, true);

        // algorithm 2: used heuristic on both number of edge and index
        //              number of edge should justify index (sigma i < m^2)
        // minCutProblem.addEdge(u, v, (c*MAXM+1)*(MAXM*MAXM) + i, true);
    }

    // algorithm 1: for each edge check if it is inside the mincut

    vector<long long> oricap = minCutProblem.cap;
    long long maxflow = minCutProblem.getMaxFlow(1, n);
    long long mincut = maxflow/MAXM, nEdge = maxflow%MAXM;

    cout << mincut << ' ' << nEdge << endl;

    for(int i = 0; i < m; i++){
        minCutProblem.cap = oricap;
        minCutProblem.cap[i*2] = 0;

        long long thisflow = minCutProblem.getMaxFlow(1, n);
        if(thisflow + oricap[i*2] == maxflow){
            cout << i+1 << endl;
            maxflow = thisflow;
            oricap[i*2] = 0;
        }
    }

    // end of algorithm 1


    // algorithm 2: used edge heuristic

    // long long maxflow = minCutProblem.getMaxFlow(1, n);
    // long long mincut = maxflow/(MAXM*MAXM)/MAXM, nEdge = (maxflow/(MAXM*MAXM))%MAXM;
    // cout << mincut << ' ' << nEdge << endl;

    // // floodfill to find saturated edge
    // vector<int> ans;

    // minCutProblem.findMinCut(ans);
    // sort(ans.begin(), ans.end());

    // for(int i = 0; i < ans.size(); i++)
    //     cout << ans[i]+1 << endl;

    // end of algorithm 2

    return 0;
}