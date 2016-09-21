// standard implementation of binary indexed tree (BIT) with 3 modes
// solve SPOJ problem: http://www.spoj.com/problems/HORRIBLE/

// all are 1-based indexing

#include <iostream>
#include <cstring>

using namespace std;

/*

// mode 1: point update, range query
int bit[100100], n;

void update(int x, int v){
    for(int i = x; i <= n; i += i&-i)
        bit[i] += v;
}

int query(int x){
    int ans = 0;
    for(int i = x; i >= 1; i -= i&-i)
        ans += bit[i];

    return ans;
}

int query(int x, int y){
    return query(y) - query(x-1);
}

*/

/*

// mode 2: range update, point query
int bit[100100], n, a[100100];

void update(int x, int v){
    for(int i = x; i <= n; i += i&-i)
        bit[i] += v;
}

void update(int x, int y, int v){
    update(x, v);
    update(y+1, -v);
}

int query(int x){
    int ans = 0;
    for(int i = x; i >= 1; i -= i&-i)
        ans += bit[i];

    return ans + a[x];
}

*/

// mode 3: range update, range query
long long bit1[100100], bit2[100100], n;

void update(long long bit[], int x, long long v){
    for(int i = x; i <= n; i += i&-i)
        bit[i] += v;
}

void update(int x, int y, long long v){
    update(bit1, x, v);
    update(bit1, y+1, -v);
    update(bit2, x, v*(x-1));
    update(bit2, y+1, -v*y);
}

long long query(long long bit[], int x){
    long long ans = 0;
    for(int i = x; i >= 1; i -= i&-i)
        ans += bit[i];

    return ans;
}

long long query(int x){
    return query(bit1, x) * x - query(bit2, x);
}

long long query(int x, int y){
    return query(y) - query(x-1);
}


int main(){
    int t;
    cin >> t;

    while(t--){
        int c;
        cin >> n >> c;

        memset(bit1, 0, sizeof bit1);
        memset(bit2, 0, sizeof bit2);

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