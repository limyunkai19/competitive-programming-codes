#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void findFixedStock(int u, int p, int q, vector<int>& stock, const vector<vector<int>>& child, const vector<int>& quantity, const vector<int>& fixed) {
    q *= quantity[u];
    if(u != 0 && fixed[u] != 0) {
        stock[u] = fixed[u];
        stock[p] -= fixed[u] * q;
    }

    if(fixed[u] != 0) {
        p = u;
        q = 1;
    }

    for(const int& v : child[u]) {
        findFixedStock(v, p, q, stock, child, quantity, fixed);
    }
}

void findDynamicStock(int u, int q, vector<int>& stock, const vector<vector<int>>& child, const vector<int>& quantity) {
    q /= quantity[u];
    if(stock[u] == 0) {
        stock[u] = q;
    }
    else {
        q = stock[u];
    }

    for(const int& v : child[u]) {
        findDynamicStock(v, q, stock, child, quantity);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> stock(n, 0), fixed(n, 0), quantity(n, 0), parent(n, 0);
    vector<vector<int>> child(n);

    cin >> stock[0];
    fixed[0] = stock[0];

    int u, type;
    for(int i = 0; i < n-1; i++) {
        u = i+1;
        cin >> type;

        cin >> parent[u] >> quantity[u];
        if(type == 2) {
            cin >> fixed[u];
        }

        parent[u]--;
        child[parent[u]].push_back(u);
    }

    findFixedStock(0, 0, 0, stock, child, quantity, fixed);
    findDynamicStock(0, 0, stock, child, quantity);

    for(int i = 0; i < n; i++) {
        cout << stock[i] << '\n';
    }
}
