// standard strongly connect component implementation using tarjan algorithm
// finding all scc will form a dag, perform top sort to do some dp on the dag
// solve hackerearth problem:
// https://www.hackerearth.com/september-clash-16/algorithm/sightseeing-walk-september-clash/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int height[100100], cur_num;
vector<vector<int> > graph, dag;
vector<int> dag_label, dag_max, dag_min, dfs_num, dfs_low, topological;
vector<bool> is_parent, visited;
stack<int> s;

void topological_sort(int u){
    visited[u] = true;
    for(int i = 0; i < dag[u].size(); i++){
        int v = dag[u][i];

        if(!visited[v])
            topological_sort(v);
    }

    topological.push_back(u);
}


void scc_dfs(int u){
    dfs_num[u] = dfs_low[u] = cur_num++;
    is_parent[u] = true;
    s.push(u);

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];

        if(dfs_num[v] == -1){
            scc_dfs(v);
        }

        // a back edge
        if(is_parent[v]){
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if(dfs_low[u] == dfs_num[u]){
        // root of the scc
        int cur_dag = dag_max.size(), v;
        dag_max.push_back(height[u]);
        dag_min.push_back(height[u]);

        do{
            v = s.top(); s.pop();
            is_parent[v] = false;

            dag_label[v] = cur_dag;
            dag_max[cur_dag] = max(dag_max[cur_dag], height[v]);
            dag_min[cur_dag] = min(dag_min[cur_dag], height[v]);

        }while(u != v);

    }
}


int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++)
            cin >> height[i];

        graph.assign(n+1, vector<int> ());
        while(m--){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        // find all scc
        dag_max.clear();
        dag_min.clear();
        dfs_num.assign(n+1, -1);
        dfs_low.assign(n+1, -1);
        dag_label.assign(n+1, -1);
        is_parent.assign(n+1, false);
        cur_num = 1;
        for(int i = 1; i <= n; i++){
            if(dfs_num[i] == -1)
                scc_dfs(i);
        }

        // build dag, dont care repeated edge,
        // just repeat it, not going to harm u in anyway
        dag.assign(dag_max.size(), vector<int> ());
        for(int i = 1; i <= n; i++){
            int u = dag_label[i];
            for(int j = 0; j < graph[i].size(); j++){
                int v = dag_label[graph[i][j]];

                if(u == v) continue;
                dag[u].push_back(v);
            }
        }

        topological.clear();
        visited.assign(dag_max.size(), false);
        for(int i = 0; i < dag_max.size(); i++){
            if(!visited[i])
                topological_sort(i);
        }

        int ans = 0;
        for(vector<int>::iterator it = topological.begin(); it != topological.end(); it++){
            int u = *it;

            for(int i = 0; i < dag[u].size(); i++){
                int v = dag[u][i];

                dag_max[u] = max(dag_max[u], dag_max[v]);
            }

            ans = max(ans, dag_max[u] - dag_min[u]);
        }

        cout << ans << endl;
    }

    return 0;
}