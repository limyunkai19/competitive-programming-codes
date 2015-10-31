/*
ID: yunkai91
LANG: C++
TASK: ditch
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

long long flow[500][500];
int p[500];
vector<vector<int> > graph;

int main(){
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);

    int n, k, a, b, w;
    cin >> k >> n;
    graph.assign(n+10, vector<int>() );
    while(k--){
        cin >> a >> b >> w;
        flow[a][b] += w;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    long long maxflow = 0;
    while(1){
        queue<int> q;
        q.push(1);
        memset(p, 0, sizeof p);
        p[1] = 1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i];
                if(p[v] == 0 && flow[u][v] > 0){
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        if(!p[n]) break;
        // find bottleneck
        long long bottleneck = 2000000000000;
        int idx = n;
        while(p[idx] != idx){
            bottleneck = min(bottleneck, flow[p[idx]][idx]);
            idx = p[idx];
        }
        //send flow
        maxflow += bottleneck;
        idx = n;
        while(p[idx] != idx){
            flow[p[idx]][idx] -= bottleneck;
            flow[idx][p[idx]] += bottleneck;
            idx = p[idx];
        }
    }

    cout << maxflow << endl;
    return 0;
}