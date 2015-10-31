/*
ID: yunkai91
LANG: C++
TASK: castle
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, graph[100][100], filling[100][100], size[10000], dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0};

int fill(int i, int j, int mark){
    filling[i][j] = mark;
    int sz = 1;

    for(int v = 0, mask = 1; v < 4; v++, mask = mask<<1){
        if( (graph[i][j]&mask) == 0){
        //cout << graph[i][j] << ' ' << mask << ' ' << (graph[i][j]&mask) << endl;
            if(filling[i+dy[v]][j+dx[v]] == -1){
                sz += fill(i+dy[v], j+dx[v], mark);
            }
        }
    }

    return sz;
}


int main(){
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    memset(filling, -1, sizeof filling);

    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> graph[i][j];
        }
    }

    int maxsize = 0, sz, component = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(filling[i][j] == -1){
                sz = fill(i, j, ++component);
                size[component] = sz;
                maxsize = max(maxsize, sz);
            }
        }
    }

    cout << component << endl << maxsize << endl;

    int maxjoint = 0, breaki, breakj;
    char breakdir;
    for(int j = 1; j <= m; j++){
        for(int i = n; i >= 1; i--){
            if(graph[i][j]&2){ //N
                if(filling[i][j] != filling[i-1][j] && size[filling[i][j]] + size[filling[i-1][j]] > maxjoint){
                    maxjoint = size[filling[i][j]] + size[filling[i-1][j]];
                    breaki = i;
                    breakj = j;
                    breakdir = 'N';
                }
            }
            if(graph[i][j]&4){ //N
                if(filling[i][j] != filling[i][j+1] && size[filling[i][j]] + size[filling[i][j+1]] > maxjoint){
                    maxjoint = size[filling[i][j]] + size[filling[i][j+1]];
                    breaki = i;
                    breakj = j;
                    breakdir = 'E';
                }
            }
        }
    }
    cout << maxjoint << endl << breaki << ' ' << breakj << ' ' << breakdir << endl;


}
