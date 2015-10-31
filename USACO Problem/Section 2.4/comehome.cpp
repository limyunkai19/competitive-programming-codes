/*
ID: yunkai91
LANG: C++
TASK: comehome
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main(){
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);

    int m;
    cin >> m;
    char a, b;
    int x;
    vector<vector<ii> > graph;
    graph.assign(300, vector<ii> () );
    while(m--){
        cin >> a >> b >> x;
        graph[a].push_back(ii(b, x));
        graph[b].push_back(ii(a, x));
    }

    vector<int> dist(300, 2000000000);
    dist['Z'] = 0;
    priority_queue<ii> pq;
    pq.push(ii(0, 'Z'));
    while(!pq.empty()){
        int u = pq.top().second, thisdist = pq.top().first; pq.pop();
        if(dist[u] != thisdist) continue;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first, w = graph[u][i].second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push(ii(dist[v], v));
            }
        }
    }

    int mindist = 2000000000;
    char mincow;
    for(int i = 'A'; i <= 'Y'; i++){
        if(dist[i] < mindist){
            mincow = i;
            mindist = dist[i];
        }
    }
    cout << mincow << ' ' << mindist << endl;

    return 0;
}