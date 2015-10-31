/*
ID: yunkai91
LANG: C++
TASK: agrinet
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int graph[200][200];
bool connected[200];

int main(){
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    int connectedfarm = 1, cost = 0;
    connected[0] = true;
    for(int i = 0; i < n; i++){
        pq.push(ii(graph[0][i], i));
    }
    while(!pq.empty()){
        int w = pq.top().first, v = pq.top().second; pq.pop();
        if(connected[v]) continue;
        cost += w;
        connected[v] = true;
        for(int i = 0; i < n; i++){
            if(!connected[i]){
                pq.push(ii(graph[v][i], i));
            }
        }
    }
    cout << cost << endl;

    return 0;
}