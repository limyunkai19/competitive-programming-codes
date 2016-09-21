// standard implementation of 2d segement tree
// solve UVa online judge problem 11297 - Census
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2272

#include <iostream>
#include <cstring>
#include <cstdio>

#define l_node  ( 2*node )
#define r_node  ( 2*node + 1 )
#define mid     ( (l+r)/2 )
#define inf     ( 1<<30 )

using namespace std;

typedef pair<int, int> ii;

int table[600][600], n, m;
ii st[2100][2100];

ii min_max(ii node_a, ii node_b){
    return ii(max(node_a.first, node_b.first), min(node_a.second, node_b.second));
}

void inity(int node, int l, int r, int nodex, int x){
    if(l == r){
        st[nodex][node] = ii(table[x][l], table[x][l]);
        return;
    }

    inity(l_node, l, mid, nodex, x);
    inity(r_node, mid+1, r, nodex, x);

    st[nodex][node] = min_max(st[nodex][l_node], st[nodex][r_node]);
}

void initx(int node, int l, int r){
    if(l == r){
        inity(1, 0, m-1, node, l);
        return;
    }

    initx(l_node, l, mid);
    initx(r_node, mid+1, r);

    // merge l, r node
    for(int i = 0; i < 4*m; i++){
        st[node][i] = min_max(st[l_node][i], st[r_node][i]);
    }
}

void init(){
    // 0-based index
    initx(1, 0, n-1);
}

void merge_update(int node, int l, int r, int x, int y, int nodex){
     if(y < l || r < y){
        // out of range
        return;
    }

    if(l == y && r == y){
        st[nodex][node] = min_max(st[2*nodex][node], st[2*nodex+1][node]);
        return;
    }

    merge_update(l_node, l, mid, x, y, nodex);
    merge_update(r_node, mid+1, r, x, y, nodex);

    st[nodex][node] = min_max(st[2*nodex][node], st[2*nodex+1][node]);
}

void updatey(int node, int l, int r, int x, int y, int val, int nodex){
    if(y < l || r < y){
        // out of range
        return;
    }

    if(l == y && r == y){
        st[nodex][node] = ii(val, val);
        return;
    }

    updatey(l_node, l, mid, x, y, val, nodex);
    updatey(r_node, mid+1, r, x, y, val, nodex);

    st[nodex][node] = min_max(st[nodex][l_node], st[nodex][r_node]);
}

void updatex(int node, int l, int r, int x, int y, int val){
    if(x < l || r < x){
        // out of range
        return;
    }

    if(l == x && r == x){
        updatey(1, 0, m-1, x, y, val, node);
        return;
    }

    updatex(l_node, l, mid, x, y, val);
    updatex(r_node, mid+1, r, x, y, val);

    // merge update
    merge_update(1, 0, m-1, x, y, node);
}

void update(int x, int y, int val){
    updatex(1, 0, n-1, x, y, val);
}

ii queryy(int node, int l, int r, int y1, int y2, int nodex){
    if(y2 < l || r < y1){
        // out of range
        return ii(-inf, inf);
    }

    if(l >= y1 && y2 >= r){
        // in range
        return st[nodex][node];
    }

    ii q1 = queryy(l_node, l, mid, y1, y2, nodex);
    ii q2 = queryy(r_node, mid+1, r, y1, y2, nodex);

    // merge update
    return min_max(q1, q2);
}

ii queryx(int node, int l, int r, int x1, int x2, int y1, int y2){
    if(x2 < l || r < x1){
        // out of range
        return ii(-inf, inf);
    }

    if(l >= x1 && x2 >= r){
        // in range
        return queryy(1, 0, m-1, y1, y2, node);
    }

    ii q1 = queryx(l_node, l, mid, x1, x2, y1, y2);
    ii q2 = queryx(r_node, mid+1, r, x1, x2, y1, y2);

    // merge update
    return min_max(q1, q2);
}

ii query(int x1, int y1, int x2, int y2){
    return queryx(1, 0, n-1, min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2));
}

int main(){
    cin >> n;
    m = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> table[i][j];
        }
    }

    init();

    int q;
    cin >> q;
    while(q--){
        char type;
        cin >> type;
        if(type == 'q'){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ii ans = query(x1-1, y1-1, x2-1, y2-1);
            cout << ans.first << ' ' << ans.second << endl;
        }
        else{
            int x, y, v;
            cin >> x >> y >> v;
            update(x-1, y-1, v);
        }
    }
    return 0;
}