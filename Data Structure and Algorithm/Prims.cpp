// Standard Prims implementation
// Solve Hackerrank problem, Prim's (MST) : Special Subtree
// link: https://www.hackerrank.com/challenges/primsmstsub

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

vector<vector<ii> > graph;

int main(){
    int n, m;
    cin >> n >> m;
    graph.assign(n, vector<ii>() );

    int a, b, c;
    while(m--){
        cin >> a >> b >> c;
        graph[a-1].push_back(ii(b-1, c));
        graph[b-1].push_back(ii(a-1, c));
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    vector<bool> visited(n, false);
    int mst = 0;
    pq.push(ii(0, 0));

    while(!pq.empty()){
        int u = pq.top().second, w = pq.top().first; pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        mst += w;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first;
            if(!visited[v]){
                pq.push(ii(graph[u][i].second, v));
            }
        }
    }

    cout << mst << endl;

	return 0;
}