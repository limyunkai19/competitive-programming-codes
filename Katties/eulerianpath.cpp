#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, bool> ib;

vector<vector<ib> > graph;
vector<int> euler_path;
bool euler_graph;

void euler_dfs(int u){
    for(int i = 0; i < graph[u].size(); i++){
        if(graph[u][i].second){
            graph[u][i].second = false;
            euler_dfs(graph[u][i].first);
        }
    }
    euler_path.push_back(u);
}

int main() {
    int n, m;
    while(cin >> n >> m && n != 0){
        graph.assign(n, vector<ib> ());
        vector<int> in_deg(n, 0);
        int n_edge = 0, non_empty;
        euler_graph = true;

        while(m--){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(ib(v, true));
            n_edge++;
            in_deg[v]++;
            non_empty = u;
        }

        int start = -1, end = -1;
        for(int i = 0; i < n; i++){
            if(graph[i].size() != in_deg[i]){
                if(graph[i].size() == in_deg[i]+1 && start == -1)
                    start = i;
                else if (graph[i].size() == in_deg[i]-1 && end == -1)
                    end = i;
                else
                    euler_graph = false;
            }
        }

        if(euler_graph){
            if(start == -1)
                start = non_empty;

            euler_path.clear();
            euler_dfs(start);
        }

        if(euler_graph && euler_path.size() == n_edge+1){
            for(int i = euler_path.size()-1; i >= 0; i--){
                cout << euler_path[i] << ' ';
            }
            cout << endl;
        }
        else{
            cout << "impossible" << endl;
        }
    }
    return 0;
}