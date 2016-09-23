// my implementation of maximun bipartite matching using Hopcroft–Karp algorithm
// solve SPOJ problem: http://www.spoj.com/problems/MATCHING/

#include <iostream>
#include <vector>
#include <queue>

#define INF (1<<30)

using namespace std;

struct Matching{
    int n, m;
    vector<vector<int> > graph;
    vector<int> match, dist;


    Matching(int _n, int _m){
        // 1-based indexing
        n = _n; m = _m;
        graph.assign(n+m+1, vector<int> ());
        match.assign(n+m+1, 0);
        dist.resize(n+1);
    }

    void addPair(int u, int v){
        graph[u].push_back(v+n);
        graph[v+n].push_back(u);
    }

    int HopcroftKarpMatching(){
        int matching = 0;
        while(bfs()){
            for(int i = 1; i <= n; i++){
                if(match[i] == 0 && dfs(i))
                    matching++;
            }
        }

        return matching;
    }

    bool bfs(){
        // 0 is the sink

        queue<int> q;
        dist[0] = INF;
        for(int i = 1; i <= n; i++){
            if(match[i] == 0){
                dist[i] = 0;
                q.push(i);
            }
            else{
                dist[i] = INF;
            }
        }

        while(!q.empty()){
            int u = q.front(); q.pop();

            if(u != 0){
                for(int i = 0; i < graph[u].size(); i++){
                    int v = graph[u][i];

                    // v is in V, match[v] is in U
                    // match[v] is 0 (not matched by default)
                    if(dist[match[v]] == INF){
                        dist[match[v]] = dist[u] + 1;
                        q.push(match[v]);
                    }
                }
            }
        }
        // check is sink is still recheable
        return dist[0] != INF;
    }

    int dfs(int u){
        // reach sink
        if(u == 0)
            return true;

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];

            if(dist[match[v]] == dist[u] + 1 && dfs(match[v])){
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        // no more match available
        return false;
    }
};

int main(){
    int n, m, e;
    scanf("%d %d %d", &n, &m, &e);

    Matching matching_problem(n, m);

    while(e--){
        int u, v;
        scanf("%d %d", &u, &v);

        matching_problem.addPair(u, v);
    }

    printf("%d\n", matching_problem.HopcroftKarpMatching());

    return 0;
}