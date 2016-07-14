#include <iostream>
#include <queue>

using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;

vector<vector<ii> > graph;
int n, m, idol[10], idol_n, idol_matrix[10][10];

// global variable for tsp
bool taken[10];
int max_taken;

void dijkstra(int idol_idx){
    vector<int> dist(n, INF);
    priority_queue<ii, vector<ii>, greater<ii> > pq;

    dist[idol[idol_idx]] = 0;
    pq.push(ii(0, idol[idol_idx]));

    while(!pq.empty()){
        int d = pq.top().first, u = pq.top().second; pq.pop();
        if(d != dist[u])
            continue;

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first, w = graph[u][i].second;

            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push(ii(dist[v], v));
            }
        }
    }

    for(int i = 0; i <= idol_n; i++){
        idol_matrix[idol_idx][i] = dist[idol[i]];
    }

}

void update_max_taken(){
    int t = 0;
    for(int i = 1; i <= idol_n; i++)
        t += taken[i];
    max_taken = max(max_taken, t);
}

void tsp(int u, int limit){
    for(int i = 1; i <= idol_n; i++){
        // try to take i
        if(!taken[i] && idol_matrix[i][u]+idol_matrix[i][0] <= limit){
            // can take, take
            taken[i] = true;
            update_max_taken();
            tsp(i, limit-idol_matrix[i][u]);
            taken[i] = false;
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        graph.assign(n, vector<ii>());

        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(ii(v, w));
            graph[v].push_back(ii(u, w));
        }

        cin >> idol_n;
        for(int i = 1; i <= idol_n; i++)
            cin >> idol[i];

        for(int i = 1; i <= idol_n; i++)
            dijkstra(i);


        // do a tsp
        max_taken = 0;
        for(int i = 1; i <= idol_n; i++)
            taken[i] = false;

        int l;
        cin >> l;
        tsp(0, l);

        cout << max_taken << endl;
    }

    return 0;
}