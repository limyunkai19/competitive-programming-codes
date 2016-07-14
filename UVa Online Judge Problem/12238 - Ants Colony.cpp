#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

vector<vector<ii> > graph;
ll dist[100010];
int parent[100010][20];
int depth[100010];

void dfs(int u){
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i].first, w = graph[u][i].second;
        if(dist[v] == -1){
            dist[v] = dist[u] + w;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v])
        return lca(v, u);

    // u is deeper

    int diff = depth[u] - depth[v];

    // advance u with diff
    for(int bit = 0; bit < 20; bit++)
        if(diff & (1<<bit) ) // if ith bit is 1, advance
            u = parent[u][bit];

    if(u != v)
    {
        for(int power = 19; power >= 0; power--) // start with highest power of 2
            if(parent[u][power] != parent[v][power])    // find higest not same parent
            {
                u = parent[u][power];
                v = parent[v][power];
            }
        u = parent[u][0];
    }
    return u;

}

int main() {
    int N;
    while(scanf("%d", &N) && N != 0){
        graph.assign(N, vector<ii>());
        memset(dist, -1, sizeof dist);
        memset(parent, -1, sizeof parent);

        int v, w;
        for(int i = 1; i < N; i++){
            //cin >> v >> w;
            scanf("%d %d", &v, &w);
            parent[i][0] = v;
            graph[i].push_back(ii(v, w));
            graph[v].push_back(ii(i, w));
        }

        for(int i = 0; i < 19; i++){
            for(int j = 0; j < N; j++){
                if(parent[j][i] != -1)
                    parent[j][i+1] = parent[parent[j][i]][i];
            }
        }

        dist[0] = 0;
        depth[0] = 0;
        dfs(0);

        int Q;
        //cin >> Q;
        scanf("%d", &Q);
        while(Q--){
            int u, v;
            //cin >> u >> v;
            scanf("%d %d", &u, &v);

            cout << dist[u]+dist[v]-2*dist[lca(u, v)];
            if(!Q) cout << endl;
            else   cout << ' ';
        }

    }


    return 0;
}