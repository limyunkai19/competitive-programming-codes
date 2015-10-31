#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool visited[100];
vector<vector<int> > graph;

void dfs(int s){
    visited[s] = true;
    for(int i = 0; i < graph[s].size(); i++){
        if(!visited[graph[s][i]]){
            dfs(graph[s][i]);
        }
    }
}

int main()
{
    int tc;
    cin >> tc; getchar(); getchar();
    int n, num;
    string temp;
    int a, b;
    while(tc--){
        getline(cin, temp);
        n = temp.at(0) - 'A' + 1;
        graph.assign(n, vector<int> () );
        getline(cin, temp);
        while(temp != ""){
            a = temp.at(0) - 'A';
            b = temp.at(1) - 'A';
            graph[a].push_back(b);
            graph[b].push_back(a);
            getline(cin, temp);
        }
        num = 0;
        memset(visited, false, sizeof visited);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                num++;
                dfs(i);
            }
        }
        cout << num << endl;
        if(tc){
            cout << endl;
        }
    }

    return 0;
}
