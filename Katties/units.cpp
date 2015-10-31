#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

map<string, int> mp;
map<int, string> rmp;
ii val[20];
vector<vector<ii> > graph, rgraph;

bool bfs(int start, int n){
    queue<int> q;
    memset(val, 0, sizeof val);
    val[start] = ii(1, start);
    q.push(start);
    while(!q.empty()){
        start = q.front(); q.pop();
        for(int i = 0; i < graph[start].size(); i++){
            int v = graph[start][i].first;
            int w = graph[start][i].second;
            if(val[v] == ii(0, 0)){
                val[v] = ii(val[start].first*w, v);
                q.push(v);
            }
        }
        for(int i = 0; i < rgraph[start].size(); i++){
            int v = rgraph[start][i].first;
            int w = rgraph[start][i].second;
            if(val[v] == ii(0, 0)){
                val[v] = ii(val[start].first/w, v);
                q.push(v);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(val[i].first == 0)
            return false;
    }
    return true;
}

int main(){
    int n, x, ia, ib;
    string a, b, s;
    while(cin >> n && n != 0){
        mp.clear();
        rmp.clear();
        graph.assign(n+10, vector<ii> ());
        rgraph.assign(n+10, vector<ii> ());
        for(int i = 0; i < n; i++){
            cin >> s;
            mp[s] = i;
            rmp[i] = s;
        }
        for(int i = 0; i < n-1; i++){
            cin >> a >> b >> x >> b;
            ia = mp[a]; ib = mp[b];
            graph[ia].push_back(ii(ib, x));
            rgraph[ib].push_back(ii(ia, x));
        }
         for(int i = 0; i < n; i++){
            if(bfs(i, n)){
                break;
            }
        }

        sort(val, val+n);
        string del = "";
        for(int i = 0; i < n; i++){
            cout << del << val[i].first << rmp[val[i].second];
            del = " = ";
        }
        cout << endl;
    }
    return 0;
}