// Standard Kruskal + Union Find Disjoint Set implementation
// Solve Hackerrank problem, Kruskal (MST): Really Special Subtree
// link: https://www.hackerrank.com/challenges/kruskalmstrsub

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<int> p;

void init(int n){
    p.resize(n);
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
}

int find_set(int x){
    if(p[x] == x)
        return x;
    return p[x] = find_set(p[x]);
}

bool is_same_set(int x, int y){
    return find_set(x) == find_set(y);
}

void union_set(int x, int y){
    p[find_set(x)] = find_set(y);
}

int main(){
    int n, m, a, b, w;
    cin >> n >> m;

    init(n);
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    while(m--){
        cin >> a >> b >> w;
        pq.push(iii(w, ii(a-1, b-1)));
    }
    int mst = 0;
    while(!pq.empty()){
        int w = pq.top().first;
        ii v = pq.top().second;
        pq.pop();

        if(!is_same_set(v.first, v.second)){
            mst += w;
            union_set(v.first, v.second);
        }
    }
    cout << mst << endl;

    return 0;
}