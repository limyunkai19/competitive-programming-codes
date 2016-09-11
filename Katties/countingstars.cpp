#include <iostream>

using namespace std;

char graph[105][105];
int dr[4] = {0, 0, -1, 1}, dc[4] = {-1, 1, 0, 0};

void fill(int i, int j){
    if(graph[i][j] == '#')
        return;
    graph[i][j] = '#';
    for(int k = 0; k < 4; k++)
        fill(i+dr[k], j+dc[k]);
}

int main(){
    int n, m, tc = 1;
    while(cin >> n >> m){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> graph[i][j];

        for(int i = 0; i <= m+1; i++)
            graph[0][i] = graph[n+1][i] = '#';
        for(int i = 0; i <= n+1; i++)
            graph[i][0] = graph[i][m+1] = '#';

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(graph[i][j] != '#')
                    fill(i, j), ans++;

        cout << "Case " << tc++ << ": " << ans << endl;
    }

    return 0;
}