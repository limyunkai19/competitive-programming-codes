#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int lounge[200200], testa[200200], testb[200200], deg[200200], pa[200200], pb[200200];
vector<vector<int> > graph;

int test(int u, int state[]){
    int ans = 0;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(state[v] == 0){
            state[v] = -state[u];
            if(state[v] > 0) ans++;
            ans += test(v, state);
        }
        else if(state[v] == state[u]){
            return -1000000000;
        }
    }
    return ans;
}

int main(){
    int n, m, a, b, w;
    cin >> n >> m;
    graph.assign(n+1, vector<int> () );
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        pa[i] = a;
        pb[i] = b;
        deg[i] = w;
        if(w == 2){
            if(lounge[a] == -1 || lounge[b] == -1){
                cout << "impossible" << endl;
                return 0;
            }
            lounge[a] = lounge[b] = 1;
            testa[a] = testa[b] = 1;
            testb[a] = testb[b] = 1;
        }
        else if(w == 0){
            if(lounge[a] == 1 || lounge[b] == 1){
                cout << "impossible" << endl;
                return 0;
            }
            lounge[a] = lounge[b] = -1;
            testa[a] = testa[b] = -1;
            testb[a] = testb[b] = -1;
        }
        else{
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    for(int i = 1; i <= n; i++){
        if(lounge[i] == 0){
            testa[i] = 1;
            a = test(i, testa)+1;
            testb[i] = -1;
            b = test(i, testb);
            if(a < 0 && b < 0){
                cout << "impossible" << endl;
                return 0;
            }
            if(a < 0){
                lounge[i] = -1;
                test(i, lounge);
            }
            else if(b < 0){
                lounge[i] = 1;
                test(i, lounge);
            }
            else if(a >= b){
                lounge[i] = -1;
                test(i, lounge);
            }
            else{
                lounge[i] = 1;
                test(i, lounge);
            }
        }
    }
    for(int i = 0; i < m; i++){
        if( (lounge[pa[i]]==1) + (lounge[pb[i]]==1) != deg[i]){
            cout << "impossible" << endl;
            return 0;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(lounge[i] > 0){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}