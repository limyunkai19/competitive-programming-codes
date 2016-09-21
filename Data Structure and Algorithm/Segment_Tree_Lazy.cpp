// standard implementation of segement tree with lazy propogation
// solve SPOJ problem: http://www.spoj.com/problems/HORRIBLE/

#include <iostream>
#include <vector>

#define l_node  ( 2*node )
#define r_node  ( 2*node + 1 )
#define mid     ( (l+r)/2 )

using namespace std;

vector<long long> st, lazy;
int a[100100], n;

void init(int node, int l, int r){
    if(l == r){
        st[node] = a[l];
        return;
    }

    init(l_node, l, mid);
    init(r_node, mid+1, r);

    st[node] = st[l_node] + st[r_node];
}

void init(){
    st.assign(4*n, 0);
    lazy.assign(4*n, 0);

    // 1-based indexing
    init(1, 1, n);
}

void update(int node, int l, int r, int x, int y, long long val){
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
        st[node] += val*(r-l+1);

        if(l != r){
            lazy[l_node] += val;
            lazy[r_node] += val;
        }
        return;
    }

    if(y < l || x > r){
        // out of range
        return;
    }

    update(l_node, l, mid, x, y, val);
    update(r_node, mid+1, r, x, y, val);

    st[node] = st[l_node] + st[r_node];
}

// range update
void update(int x, int y, int val){
    update(1, 1, n, x, y, val);
}

// point update
void update(int k, int val){
    update(1, 1, n, k, k, val);
}

long long query(int node, int l, int r, int x, int y){
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

    long long q1 = query(l_node, l, mid, x, y);
    long long q2 = query(r_node, mid+1, r, x, y);

    return q1 + q2;
}

// range query
long long query(int x, int y){
    return query(1, 1, n, x, y);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int c;
        cin >> n >> c;

        init();
        while(c--){
            int type, x, y, val;
            cin >> type;

            if(type == 0){
                cin >> x >> y >> val;
                update(x, y, val);
            }
            else{
                cin >> x >> y;
                cout << query(x, y) << '\n';
            }
        }
    }

    return 0;
}