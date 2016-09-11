#include <iostream>

using namespace std;

#define INF 1000000000

int graph[160][160];

int main(){
    int n, m, q;

    while(cin >> n >> m >> q && n != 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                graph[i][j] = INF;
            }
            graph[i][i] = 0;
        }

        while(m--){
            int u, v, x;
            cin >> u >> v >> x;

            graph[u][v] = min(graph[u][v], x);
        }

        for(int k = 0; k < n; k++)
            for(int u = 0; u < n; u++)
                for(int v = 0; v < n; v++)
                    if( graph[u][k] != INF && graph[k][v] != INF )
                        graph[u][v] = min(graph[u][v], graph[u][k]+graph[k][v]);

        for(int k = 0; k < n; k++)
            for(int u = 0; u < n; u++)
                for(int v = 0; v < n; v++)
                    if( graph[u][k] != INF && graph[k][v] != INF && graph[k][k] < 0 )
                        graph[u][v] = -INF;

        while(q--){
            int u, v;
            cin >> u >> v;
            if(graph[u][v] == INF)
                cout << "Impossible" << endl;
            else if(graph[u][v] != -INF)
                cout << graph[u][v] << endl;
            else
                cout << "-Infinity" << endl;
        }
        cout << endl;
    }

    return 0;
}