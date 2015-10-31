#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<set<int> > graph;

int built[100100];

int main(){
    int n, a, b;
    cin >> n;
    graph.assign(n+1, set<int> () );
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(graph[a].count(b) == 1){
            built[a] = b;
            built[b] = a;
            graph[a].erase(b);
            graph[b].erase(a);
        }
        else{
            graph[a].insert(b);
            graph[b].insert(a);
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(graph[i].size() == 1 && built[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        int v = *graph[u].begin();
        graph[u].erase(v);
        graph[v].erase(u);
        built[u] = v;
        if(graph[v].size() == 1 && built[v] == 0)
            q.push(v);
    }
    for(int i = 1; i <= n; i++){
        if(graph[i].size() != 0 && built[i] == 0){
            int u = i, v = *graph[i].begin();
            built[u] = v;
            graph[u].erase(v);
            graph[v].erase(u);
            while(graph[v].size() != 0 && built[v] == 0){
                u = v;
                v = *graph[u].begin();
                built[u] = v;
                graph[u].erase(v);
                graph[v].erase(u);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << ' ' << built[i] << endl;
    }

}