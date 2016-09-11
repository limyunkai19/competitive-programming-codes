#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > graph;
map<string, int> mp;
string rev_mp[100010];
int color[100010];
bool bipartite = true;
vector<string> a, b;

void fill(int u, int c){
    if(color[u] != 0){
        if(color[u] != c)
            bipartite = false;
        return;
    }

    color[u] = c;
    if(c == 1) a.push_back(rev_mp[u]);
    else       b.push_back(rev_mp[u]);

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        fill(v, -c);
    }
}

int main(){
    int n;
    cin >> n;
    graph.assign(n, vector<int>());

    for(int i = 0; i < n; i++){
        cin >> rev_mp[i];
        mp[rev_mp[i]] = i;
    }

    int m;
    cin >> m;
    while(m--){
        string u, v;
        cin >> u >> v;

        int U, V;
        U = mp[u];
        V = mp[v];

        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            fill(i, 1);
        }
    }

    if(!bipartite){
        cout << "impossible" << endl;
    }
    else{
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        for(int i = 0; i < b.size(); i++){
            cout << b[i] << ' ';
        }
        cout << endl;

    }

    return 0;
}
