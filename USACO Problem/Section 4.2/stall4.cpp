/*
ID: yunkai91
LANG: C++
TASK: stall4
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int> > graph(402, vector<int>() );
int flow[500][500];

int main(){
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);

    int cow, stall;
    cin >> cow >> stall;

    int source = 0, destination = 401, offset = 200;
    for(int i = 1; i <= cow; i++){
        graph[source].push_back(i);
        graph[i].push_back(source);
        flow[source][i] = 1;
    }
    for(int i = 1; i <= stall; i++){
        graph[destination].push_back(i+offset);
        graph[i+offset].push_back(destination);
        flow[i+offset][destination] = 1;
    }

    for(int i = 1; i <= cow; i++){
        int m, x;
        cin >> m;
        while(m--){
            cin >> x;
            graph[x+offset].push_back(i);
            graph[i].push_back(x+offset);
            flow[i][x+offset] = 1;
        }
    }

    int maxmatch = 0, p[402];
    queue<int> q;
    while(1){
        memset(p, -1, sizeof p);
        p[source] = source;
        q.push(source);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i];
                if(p[v] == -1 && flow[u][v] > 0){
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        if(p[destination] == -1) break;

        int bottleneck = 100000000, idx = destination;
        while(p[idx] != idx){
            bottleneck = min(bottleneck, flow[p[idx]][idx]);
            idx = p[idx];
        }
        maxmatch += bottleneck;
        idx = destination;
        while(p[idx] != idx){
            flow[p[idx]][idx] -= bottleneck;
            flow[idx][p[idx]] += bottleneck;
            idx = p[idx];
        }
    }
    cout << maxmatch << endl;

    return 0;
}