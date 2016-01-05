#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<long long, int> lli;

long long a[500010], sum[500010];
vector<long long> st, lazy;
int n;


long long init(int node, int l, int r){
    lazy[node] = 0;
    if(l == r){
        st[node] = sum[l];
        return st[node];
    }
    int lnode = 2*node, rnode = 2*node+1, mid = (l+r)/2;

    return st[node] = max(init(lnode, l, mid), init(rnode, mid+1, r));
}

void init(int n){
    st.resize(4*n); lazy.resize(4*n);
    init(1, 1, n);
}

/* lli query(int node, int l, int r, int i, int j){
    if(i <= l && j >= r){
        return lli(st[node] + lazy[node], idx[node]);
    }
    if(i > r || j < l){
        return lli(-1000000000000000000LL, -1);
    }

    int lnode = 2*node, rnode = 2*node+1, mid = (l+r)/2;
    lazy[lnode] += lazy[node];
    lazy[rnode] += lazy[node];
    lazy[node] = 0;

    return max(query(lnode, l, mid, i, j), query(rnode, mid+1, r, i, j));
}
*/

int query(int node, int l, int r, int x){
    if(l == r){
        if(st[node]+lazy[node] >= x){
            return l;
        }
    }

    if(st[node]+lazy[node] < x){
        return -1;
    }

    int lnode = 2*node, rnode = 2*node+1, mid = (l+r)/2;
    lazy[lnode] += lazy[node];
    lazy[rnode] += lazy[node];
    st[node] += lazy[node];
    lazy[node] = 0;

    // travel to left if possible
    if(st[lnode]+lazy[lnode] >= x){
        return query(lnode, l, mid, x);
    }
    else{
        return query(rnode, mid+1, r, x);
    }
}

int query(int x){
    return query(1, 1, n, x);
}

void update(int node, int l, int r, int i , int j, long long x){
    if(i <= l && j >= r){
        lazy[node] += x;
        return;
    }
    if(i > r || j < l){
        return;
    }

    int lnode = 2*node, rnode = 2*node+1, mid = (l+r)/2;
    lazy[lnode] += lazy[node];
    lazy[rnode] += lazy[node];
    lazy[node] = 0;

    update(lnode, l, mid, i, j, x);
    update(rnode, mid+1, r, i, j, x);

    st[node] = max(st[lnode]+lazy[lnode], st[rnode]+lazy[rnode]);
}

void update(long long x, int i, int j){
    update(1, 1, n, i, j, x);
}


int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--){
        int x;
        cin >> n >> x;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum[i] = sum[i-1]+a[i];
        }

        init(n);

        int ans = n+1;
        for(int i = 1; i <= n; i++){
            int range = query(x); // query left most node > x
            if(range != -1)
                ans = min(range-i+1, ans);
            update(-a[i], i, n);
            update(-100000000000000000LL, i, i);
        }

        cout << (ans==n+1?-1:ans) << endl;
    }

    return 0;
}