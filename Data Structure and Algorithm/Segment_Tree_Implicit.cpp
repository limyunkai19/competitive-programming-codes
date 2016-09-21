// standard implementation of implicit segement tree
// solve SPOJ problem: http://www.spoj.com/problems/HORRIBLE/

#include <iostream>
#include <cstdio>
#include <vector>

#define mid ( (l+r)/2 )

using namespace std;

struct st_node{
    int l, r;
    long long val, lazy;

    st_node *l_node, *r_node;

    st_node(int _l, int _r){
        l = _l; r = _r;
        l_node = NULL; r_node = NULL;
    }

    void expand_node(){
        if(l_node == NULL){
            l_node = new st_node(l, mid);
            r_node = new st_node(mid+1, r);
        }
    }

    void clear_lazy(){
        if(lazy != 0){
            val += lazy*(r-l+1);

            if(l != r){
                this->expand_node();

                l_node->lazy += lazy;
                r_node->lazy += lazy;
            }

            lazy = 0;
        }
    }
};

void update(st_node* node, int x, int y, long long val){
    node->clear_lazy();

    int l = node->l, r = node->r;

    if(x <= l && r <= y){   // in range, lazy update it
        // ensure this node value is correct for parent updating
        node->val += val*(r-l+1);

        if(l != r){
            node->expand_node();

            node->l_node->lazy += val;
            node->r_node->lazy += val;
        }
        return;
    }

    if(y < l || x > r){
        // out of range
        return;
    }

    node->expand_node();
    update(node->l_node, x, y, val);
    update(node->r_node, x, y, val);

    node->val = node->l_node->val + node->r_node->val;
}


long long query(st_node* node, int x, int y){
    node->clear_lazy();

    int l = node->l, r = node->r;

    if(x <= l && r <= y){
        // in range, return value
        return node->val;
    }

    if(y < l || x > r){
        // out of range
        return 0;
    }

    node->expand_node();
    long long q1 = query(node->l_node, x, y);
    long long q2 = query(node->r_node, x, y);

    return q1 + q2;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, c;
        cin >> n >> c;

        st_node* root = new st_node(1, n);
        while(c--){
            int type, x, y, val;
            cin >> type;

            if(type == 0){
                cin >> x >> y >> val;
                update(root, x, y, val);
            }
            else{
                cin >> x >> y;
                cout << query(root, x, y) << '\n';
            }
        }
    }

    return 0;
}