#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<double, ii> dii;

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
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++){
        int n, r;
        cin >> n >> r;
        vector<double> x(n), y(n);
        vector<dii> edge;
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
            for(int j = 0; j < i; j++){
                edge.push_back(dii( sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])), ii(i, j)));
            }
        }
        sort(edge.begin(), edge.end());

        double road = 0, rail = 0;
        init(n);
        for(int i = 0; i < edge.size(); i++){
            double w = edge[i].first;
            int u = edge[i].second.first, v = edge[i].second.second;

            if(!same_set(u, v)){
                if(w <= r){
                    road += w;
                    n--;
                }
                else{
                    rail += w;
                }

                union_set(u, v);
            }
        }

        cout << "Case #" << t << ": " << n << ' ' << (int)(road+0.5) << ' ' << (int)(rail+0.5) << endl;

    }


    return 0;
}