// standard implementation of implicit 2d segement tree
// partially solve SPOJ problem: http://www.spoj.com/problems/NKTEAM/

// O(n log^2 n), fesible for n < 10^4 - 10^5

// change the range of st_node1 and st_node2


#include <iostream>
#include <cstring>
#include <cstdio>

#define mid     ( (l+r)/2 )
#define inf     ( 1<<30 )
#define MAX     ( 1000000100 )

using namespace std;

int n;

struct st_node2{
    int l, r, val;

    st_node2 *l_node, *r_node;

    st_node2(int _l, int _r){
        l = _l; r = _r; val = 0;
        l_node = NULL; r_node = NULL;
    }

    void expand_node(){
        if(l_node == NULL){
            l_node = new st_node2(l, mid);
            r_node = new st_node2(mid+1, r);
        }
    }

};

struct st_node1{
    int l, r;
    st_node2 *node2_root;
    st_node1 *l_node, *r_node;

    st_node1(int _l, int _r){
        l = _l; r = _r;
        l_node = NULL; r_node = NULL;
        node2_root = new st_node2(1, n);
    }

    void expand_node(){
        if(l_node == NULL){
            l_node = new st_node1(l, mid);
            r_node = new st_node1(mid+1, r);
        }
    }
};

void updatey(st_node2* node, int x, int y, int val){
    int l = node->l, r = node->r;
    if(y < l || r < y){
        // out of range
        return;
    }

    if(l == y && r == y){
        node->val = max(node->val, val);
        return;
    }

    node->expand_node();
    updatey(node->l_node, x, y, val);
    updatey(node->r_node, x, y, val);

    node->val = max(node->val, val);
}

void update(st_node1* node, int x, int y, int val){
    int l = node->l, r = node->r;
    if(x < l || r < x){
        // out of range
        return;
    }

    if(l == x && r == x){
        updatey(node->node2_root, x, y, val);
        return;
    }

    node->expand_node();
    update(node->l_node, x, y, val);
    update(node->r_node, x, y, val);

    updatey(node->node2_root, x, y, val);
}

int queryy(st_node2* node, int y1, int y2){
    int l = node->l, r = node->r;
    if(y2 < l || r < y1){
        // out of range
        return 0;
    }

    if(l >= y1 && y2 >= r){
        // in range
        return node->val;
    }

    node->expand_node();
    int q1 = queryy(node->l_node, y1, y2);
    int q2 = queryy(node->r_node, y1, y2);

    // merge update
    return max(q1, q2);
}

int query(st_node1* node, int x1, int x2, int y1, int y2){
    int l = node->l, r = node->r;
    if(x2 < l || r < x1){
        // out of range
        return 0;
    }

    if(l >= x1 && x2 >= r){
        // in range
        return queryy(node->node2_root, y1, y2);
    }

    node->expand_node();
    int q1 = query(node->l_node, x1, x2, y1, y2);
    int q2 = query(node->r_node, x1, x2, y1, y2);

    // merge update
    return max(q1, q2);
}

int x[500010], y[500010], ranks[500010];

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", ranks+i);

    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        x[t] = i+1;
    }
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        y[t] = i+1;
    }

    st_node1* root = new st_node1(1, n);

    int ans = 0;
    for(int idx = 0; idx < n; idx++){
        int i = ranks[idx];

        int f = query(root, 1, x[i], 1, y[i]);

        ans += (f^1);

        update(root, x[i], y[i], 1);
    }

    cout << ans << endl;

    return 0;
}
