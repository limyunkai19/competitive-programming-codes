#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > dist(410, vector<int> (410, 1000000000));

int main(){
    int n, m, a, b, w;
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> w;
        dist[a][b] = w;
    }

    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    int q;
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(a == b)
            cout << 0 << endl;
        else if(dist[a][b] == 1000000000)
            cout << -1 << endl;
        else
            cout << dist[a][b] << endl;
    }
    return 0;
}