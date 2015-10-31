/*
ID: yunkai91
LANG: C++
TASK: fence
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

typedef pair<int, int> ii;

vector<set<ii> > graph(510, set<ii> ());
vector<int> ans;

void dfs_euler(int u){
    while(graph[u].size() > 0){
        //visit next;
        int next = graph[u].begin()->first;
        int    m = graph[u].begin()->second;
        graph[u].erase(ii(next, m));
        graph[next].erase(ii(u, m));
        dfs_euler(next);
    }
    ans.push_back(u);
}

int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    int m, a, b;
    cin >> m;
    while(m--){
        cin >> a >> b;
        graph[a].insert(ii(b,m));
        graph[b].insert(ii(a,m));
    }

    int pos = 0;
    for(int i = 1; i <= 500; i++){
        if(graph[i].size() == 0) continue;
        if(pos == 0)
            pos = i;
        if(graph[i].size()%2 == 1){
            pos = i;
            break;
        }
    }
    dfs_euler(pos);
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << endl;

    return 0;
}