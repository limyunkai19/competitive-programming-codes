#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int a, b;
vector<vector<int> > graph;
int visited[100010];

void dfs(int s){
    for(int i = 0; i < graph[s].size(); i++){
        if(visited[graph[s][i]] == 0){
            if(visited[s] == 1){
                visited[graph[s][i]] = 2;
                b++;
            }
            else{
                visited[graph[s][i]] = 1;
                a++;
            }
            dfs(graph[s][i]);
        }
    }
}

int main()
{
    freopen("arthin.txt", "r", stdin);
    freopen("arthout.txt", "w", stdout);

    int n, p;
    //cin >> n >> p;
    scanf("%d %d", &n, &p);
    graph.assign(n, vector<int> () );
    memset(visited, 0, sizeof visited);
    for(int i = 0; i < p; i++){
        //cin >> a >> b;
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            a=1; b=0;
            dfs(i);
            ans += max(a, b);
        }
    }
    cout << ans << endl;

    return 0;
}
