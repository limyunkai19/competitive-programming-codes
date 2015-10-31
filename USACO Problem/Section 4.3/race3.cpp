/*
ID: yunkai91
LANG: C++
TASK: race3
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > directed(110, vector<int> () ), undirected(110, vector<int>() );
bool visited[110];
int n;

bool can_reach(vector<vector<int> > &graph){
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return visited[n];
}

int main(){
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);

    for(n = 0; ; n++){
        int x;
        while(cin >> x && x >= 0){
            directed[n].push_back(x);
            undirected[n].push_back(x);
            undirected[x].push_back(n);
        }
        if(directed[n].size() == 0) break;
    }

    vector<int> ans1, ans2;
    for(int i = 1; i < n; i++){
        memset(visited, 0, sizeof visited);
        visited[i] = true;
        if(!can_reach(directed)){
            ans1.push_back(i);
        }
    }
    for(int i = 0; i < ans1.size(); i++){
        memset(visited, 0, sizeof visited);
        visited[ans1[i]] = true;
        if(!can_reach(undirected)){
            int ans = true;
            visited[ans1[i]] = false;
            for(int j = 0; j < directed[ans1[i]].size(); j++){
                int v = directed[ans1[i]][j];
                if(visited[v]){
                    ans = false;
                    break;
                }
            }
            if(ans)
                ans2.push_back(ans1[i]);
        }
    }
    cout << ans1.size();
    for(int i = 0; i < ans1.size(); i++){
        cout << ' ' << ans1[i];
    }
    cout << endl;
    cout << ans2.size();
    for(int i = 0; i < ans2.size(); i++){
        cout << ' ' << ans2[i];
    }
    cout << endl;

    return 0;
}