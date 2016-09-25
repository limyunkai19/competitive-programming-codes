// my implementation of heavy light decomposition on tree
// solve SPOJ problem: http://www.spoj.com/problems/QTREE/
// reference: https://blog.anudeep2011.com/heavy-light-decomposition/


// change segment tree merge, query merge
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

// change this
#define MAXN 100100
#define LN   20

#define l_node  ( 2*node )
#define r_node  ( 2*node + 1 )
#define mid     ( (l+r)/2 )

typedef pair<int, int> ii;

int n;
vector<vector<ii> > graph;
int parent[MAXN][LN], subtree[MAXN], depth[MAXN], specialChild[MAXN], chainId[MAXN], edgePosInChain[MAXN];

void init(int node, int l, int r, vector<int>& st, vector<int>& a);
void update(int node, int l, int r, int x, int y, long long val, vector<int>& st, vector<int>& lazy);
int query(int node, int l, int r, int x, int y, vector<int>& st, vector<int>& lazy);

struct Chain{
    int connect, id;
    vector<int> chainEdge, st, lazy;

    Chain(int u, int _id){
        id = _id;
        connect = u;
    }

    void insert(int v, int w){
        edgePosInChain[v] = chainEdge.size();
        chainEdge.push_back(w);
        chainId[v] = id;
    }

    void initST(){
        st.assign(4*chainEdge.size(), 0);
        lazy.assign(4*chainEdge.size(), 0);

        init(1, 0, chainEdge.size()-1, st, chainEdge);
    }

    int queryChain(int v){
        return query(1, 0, chainEdge.size()-1, 0, edgePosInChain[v], st, lazy);
    }

    int queryChain(int u, int v){
        return query(1, 0, chainEdge.size()-1, edgePosInChain[u]+1, edgePosInChain[v], st, lazy);
    }

    void updateChain(int v, int w){
        int pos = edgePosInChain[v];
        chainEdge[pos] = w;
        update(1, 0, chainEdge.size()-1, pos, pos, w, st, lazy);
    }

};

void dfs(int u, int p, int d){
    parent[u][0] = p;
    subtree[u] = 1;
    depth[u] = d;

    specialChild[u] = -1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i].first;

        if(v == p) continue;
        dfs(v, u, d+1);
        subtree[u] += subtree[v];

        if(specialChild[u] == -1 || subtree[v] > subtree[specialChild[u]])
            specialChild[u] = v;
    }
}

vector<Chain*> hldChain;
void HLD(int u, int u_w, Chain* chain){
    chain->insert(u, u_w);

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i].first, w = graph[u][i].second;

        if(v == parent[u][0]) continue;
        if(v == specialChild[u]){
            // extend chain
            HLD(v, w, chain);
        }
        else{
            // new chain
            hldChain.push_back(new Chain(u, hldChain.size()));
            HLD(v, w, hldChain.back());
        }
    }
}

void HLD(int root){
    memset(parent, -1, sizeof parent);

    dfs(root, -1, 0);
    for(int i = 0; i < LN-1; i++){
        for(int j = 0; j < n; j++){
            if(parent[j][i] != -1)
                parent[j][i+1] = parent[parent[j][i]][i];
        }
    }


    hldChain.push_back(new Chain(-1, hldChain.size()));
    HLD(root, -1, hldChain.back());

    for(int i = 0; i < hldChain.size(); i++)
        hldChain[i]->initST();
}

// each edge has 1-1 correspondent with a vertex except root
// v-par[v] edge is uniquely determine by v
void update(int v, int val){
    hldChain[chainId[v]]->updateChain(v, val);
}

int lca(int u, int v){
    if(depth[u] < depth[v])
        return lca(v, u);

    // u is deeper

    int diff = depth[u] - depth[v];

    // advance u with diff
    for(int bit = 0; bit < LN; bit++)
        if(diff & (1<<bit) ) // if ith bit is 1, advance
            u = parent[u][bit];

    if(u != v)
    {
        for(int power = LN-1; power >= 0; power--) // start with highest power of 2
            if(parent[u][power] != parent[v][power])    // find higest not same parent
            {
                u = parent[u][power];
                v = parent[v][power];
            }
        u = parent[u][0];
    }
    return u;

}

int queryHLD(int u, int v){
    int ans = 0;
    while(chainId[u] != chainId[v]){
        ans = max(hldChain[chainId[u]]->queryChain(u), ans);
        u = hldChain[chainId[u]]->connect;
    }

    return max(ans, hldChain[chainId[u]]->queryChain(v, u));
}

int query(int u, int v){
    int l = lca(u, v);

    int q1 = queryHLD(u, l);
    int q2 = queryHLD(v, l);

    return max(q1, q2);
}

int main(){
    int t;
    scanf("%d ", &t);

    while(t--){
        scanf("%d", &n);

        vector<ii> edge;
        graph.assign(n, vector<ii>());
        for(int i = 0; i < n-1; i++){
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            u--; v--;
            graph[u].push_back(ii(v, c));
            graph[v].push_back(ii(u, c));
            edge.push_back(ii(u, v));
        }

        HLD(0);

        char type[10];
        scanf("%s", type);
        while(type[0] != 'D'){
            int a, b;
            scanf("%d %d", &a, &b);

            if(type[0]=='Q'){
                printf("%d\n", query(a-1, b-1));
            }
            else{
                int u = edge[a-1].first, v = edge[a-1].second;

                update(depth[u]>depth[v]?u:v, b);
            }

            scanf("%s", type);
        }
    }

    return 0;
}

// segment tree
void init(int node, int l, int r, vector<int>& st, vector<int>& a){
    if(l == r){
        st[node] = a[l];
        return;
    }

    init(l_node, l, mid, st, a);
    init(r_node, mid+1, r, st, a);

    st[node] = max(st[l_node], st[r_node]);
}

void update(int node, int l, int r, int x, int y, long long val, vector<int>& st, vector<int>& lazy){
    if(lazy[node] != 0){
        // update this node
        st[node] += lazy[node]*(r-l+1);

        if(l != r){
            // propogate down
            lazy[l_node] += lazy[node];
            lazy[r_node] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(x <= l && r <= y){   // in range, lazy update it
        // ensure this node value is correct for parent updating
        // st[node] += val*(r-l+1);

        // if(l != r){
        //     lazy[l_node] += val;
        //     lazy[r_node] += val;
        // }
        st[node] = val;
        return;
    }

    if(y < l || x > r){
        // out of range
        return;
    }

    update(l_node, l, mid, x, y, val, st, lazy);
    update(r_node, mid+1, r, x, y, val, st, lazy);

    st[node] = max(st[l_node], st[r_node]);
}

int query(int node, int l, int r, int x, int y, vector<int>& st, vector<int>& lazy){
    if(lazy[node] != 0){
        // update this node
        st[node] += lazy[node]*(r-l+1);

        if(l != r){
            // propogate down
            lazy[l_node] += lazy[node];
            lazy[r_node] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(x <= l && r <= y){
        // in range, return value
        return st[node];
    }

    if(y < l || x > r){
        // out of range
        return 0;
    }

    long long q1 = query(l_node, l, mid, x, y, st, lazy);
    long long q2 = query(r_node, mid+1, r, x, y, st, lazy);

    return max(q1, q2);
}