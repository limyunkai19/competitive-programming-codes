#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

vector<int> p;

void init(int n){
    p.resize(n);
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
}

int find_set(int i){
    if(p[i] == i) return i;
    return p[i] = find_set(p[i]);
}

bool same_set(int u, int v){
    return find_set(u) == find_set(v);
}

void union_set(int u, int v){
    p[find_set(u)] = find_set(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m && n != 0){
        vector<pii> edge;
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back(pii(w, ii(u, v)));
        }

        sort(edge.begin(), edge.end());
        init(n);
        vector<int> ans;

        for(int i = 0; i < edge.size(); i++){
            int w = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;

            if(!same_set(u, v)){
                union_set(u, v);
            }
            else{
                ans.push_back(w);
            }
        }

        if(ans.size() == 0){
            cout << "forest" << endl;
        }
        else{
            cout << ans[0];
            for(int i = 1; i < ans.size(); i++){
                cout << ' ' << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}