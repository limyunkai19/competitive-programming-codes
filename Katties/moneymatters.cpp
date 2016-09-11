#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int> > graph;
vector<int> money;

int dfs(int u){
    visited[u] = true;
    int total = money[u];

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v])
            total += dfs(v);
    }
    return total;
}

int main(){
    int n, m;
    cin >> n >> m;

    money.resize(n);
    graph.assign(n, vector<int> ());
    visited.assign(n, false);

    for(int i = 0; i < n; i++)
        cin >> money[i];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i] && dfs(i) != 0){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << "POSSIBLE" << endl;
    return 0;
}