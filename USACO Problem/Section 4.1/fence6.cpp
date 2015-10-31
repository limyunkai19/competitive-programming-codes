/*
ID: yunkai91
LANG: C++
TASK: fence6
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<vector<int> > leftfence, rightfence, fence;
int weight[200];

int dijikstra(int s, int n){
    vector<int> dist(n+10, (1<<28)), parent(n+10);
    priority_queue<ii, vector<ii>, greater<ii> > pq;

    for(int i = 0; i < leftfence[s].size(); i++){
        pq.push(ii(weight[s], leftfence[s][i]));
        dist[leftfence[s][i]] = weight[s];
        parent[leftfence[s][i]] = s;
    }
    dist[s] = 0;

    int ans = (1<<29);
    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(dist[u] != w) continue;

        for(int i = 0; i < fence[u].size(); i++){
            int v = fence[u][i];
            if(dist[v] > dist[u]+weight[u]){
                dist[v] = dist[u] + weight[u];
                parent[v] = u;
                pq.push(ii(dist[v], v));
            }
            if(v == s && parent[u] != s){
                ans = min(ans, dist[u]+weight[u]);
            }
        }
    }

    return ans;
}

int main(){
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);

    int n, u, v, w, l, r;
    cin >> n;
    leftfence.assign(n+10, vector<int>() );
    rightfence.assign(n+10, vector<int>() );
    fence.assign(n+10, vector<int>() );
    for(int i = 0; i < n; i++){
        cin >> u >> w;
        pq.push(ii(w, u));
        weight[u] = w;
        cin >> l >> r;
        while(l--){
            cin >> v;
            leftfence[u].push_back(v);
            fence[u].push_back(v);
        }
        while(r--){
            cin >> v;
            rightfence[u].push_back(v);
            fence[u].push_back(v);
        }
    }

    int ans = (1<<29);
    for(int i = 1; i <= n; i++){
        ans = min(ans, dijikstra(i, n));
    }

    cout << ans << endl;

    return 0;
}