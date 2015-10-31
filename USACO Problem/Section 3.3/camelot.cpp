/*
ID: yunkai91
LANG: C++
TASK: camelot
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>

using namespace std;

typedef pair<int, int> ii;

int knightr[8] = {1, 1, -1, -1, 2, 2, -2, -2}, knightc[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int kingr[8] = {1, 1, 1, -1, -1, -1, 0, 0}, kingc[8] = {1, -1, 0, 1, -1, 0, 1, -1};
vector<int> piecer, piecec;
int r, c;

int shortest[35][30][35][30];

void bfs(int a, int b){
    shortest[a][b][a][b] = 0;
    queue<ii> q;
    q.push(ii(a, b));
    while(!q.empty()){
        int ur = q.front().first, uc = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int vr = ur+knightr[i], vc = uc+knightc[i];
            if( vr >= 0 && vr < r && vc >= 0 && vc < c){
                if(shortest[a][b][vr][vc] == 1<<20){
                    shortest[a][b][vr][vc] = shortest[a][b][ur][uc]+1;
                    q.push(ii(vr, vc));
                }
            }
        }
    }
}

int main(){
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);

    char a;
    int b;
    cin >> r >> c;

    while(cin >> a >> b){
        piecer.push_back(b-1);
        piecec.push_back(a-'A');
    }

    for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
    for(int a = 0; a < r; a++)
    for(int b = 0; b < c; b++)
        shortest[i][j][a][b] = 1<<20;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            bfs(i, j);
        }
    }

    int ans = 1<<29;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            // set i j as meeting point
            int step = 0;
            for(int k = 1; k < piecer.size(); k++){
                step += shortest[i][j][piecer[k]][piecec[k]];
            }
            for(int k = 1; k < piecer.size(); k++){
                ans = min(ans,
                    step - shortest[i][j][piecer[k]][piecec[k]] +
                    shortest[i][j][piecer[0]][piecec[0]] + shortest[piecer[0]][piecec[0]][piecer[k]][piecec[k]]);
                for(int kr = -2; kr <= 2; kr++)
                    for(int kc = -2; kc <= 2; kc++){
                    if(piecer[0]+kr < 0 || piecer[0]+kr >= r || piecec[0]+kc < 0 || piecec[0]+kc >= c)
                        continue;
                    ans = min(ans,
                    step - shortest[i][j][piecer[k]][piecec[k]] + max(abs(kr), abs(kc)) +
                    shortest[i][j][piecer[0]+kr][piecec[0]+kc] + shortest[piecer[0]+kr][piecec[0]+kc][piecer[k]][piecec[k]]);
                }
            }
            ans = min(ans, step+max(abs(i-piecer[0]),abs(j-piecec[0]))); // king self walk
            // cout << i << ' ' << j << ' ' << step << ' ' << ans << endl;
        }
    }
    cout << ans << endl;

    return 0;
}
