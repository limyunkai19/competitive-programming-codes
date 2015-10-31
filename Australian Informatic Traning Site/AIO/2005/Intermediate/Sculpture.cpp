#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

vector<vector<ii> > graph;
vector<int> seq;
int dist[50005];

int main()
{
    freopen("sculpin.txt", "r", stdin);
    freopen("sculpout.txt", "w", stdout);
    memset(dist, 0, sizeof dist);

    int n, a, w;
    cin >> n;
    graph.assign(n, vector<ii> () );
    for(int i = 0; i < n; i++){
        cin >> a >> w;
        graph[i].push_back(ii(a-1, w));
        cin >> a >> w;
        graph[i].push_back(ii(a-1, w));
    }

    queue<int> q;
    q.push(0);
    int s;
    while(!q.empty()){
        s = q.front(); q.pop();
        if(graph[s][0].second != 0){
            seq.push_back(s);
            for(int i = 0; i < graph[s].size(); i++){
                dist[graph[s][i].first] = dist[s] + graph[s][i].second;
                q.push(graph[s][i].first);
            }
        }
    }

    int ans = 0;
    for(int i = seq.size()-1; i >= 0; i--){
        ans += abs(dist[graph[seq[i]][0].first] - dist[graph[seq[i]][1].first]);
        dist[seq[i]] = max(dist[graph[seq[i]][0].first], dist[graph[seq[i]][1].first]);
    }
    cout << ans << endl;

    return 0;
}
