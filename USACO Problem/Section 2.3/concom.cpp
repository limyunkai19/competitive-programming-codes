/*
ID: yunkai91
LANG: C++
TASK: concom
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int stock[110][110];
bool control[110][110];

int main(){
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    for(int i = 0; i < 105; i++) control[i][i] = true;

    queue<ii> q;
    int m;
    int a, b, x;
    cin >> m;
    while(m--){
        cin >> a >> b >> x;
        stock[a][b] += x;
        if(stock[a][b] > 50) q.push(ii(a, b));
    }

    while(!q.empty()){
        a = q.front().first; b = q.front().second; q.pop();
        if(control[a][b]) continue;
        //a controlled b, all stock of b should be a;
        control[a][b] = true;
        for(int i = 0; i < 105; i++){
            stock[a][i] += stock[b][i];
            if(stock[a][i] > 50 && !control[a][i]) q.push(ii(a, i));
        }
    }

    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            if(control[i][j] && i != j){
                cout << i << ' ' << j << endl;
            }
        }
    }

    return 0;
}