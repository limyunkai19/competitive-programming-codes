#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<int> p; vector<bool> inmst;

int init(int n){p.resize(n+1); for(int i = 0; i <= n; i++) p[i] = i;}
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(ii edge) { return findSet(edge.first) == findSet(edge.second); }
void unionSet(ii edge) {p[findSet(edge.first)] = findSet(edge.second);}

int mst(vector<iii>& edge, int n, int ignore, bool needflag){
    int ans = 0, take = 0; init(n);
    for(int i = 0; i < edge.size(); i++){
        if(ignore == i || isSameSet(edge[i].second)) continue;
        ans += edge[i].first; take++; unionSet(edge[i].second);
        if(needflag) inmst[i] = true;
    }
    return (take==n-1)?ans:(1<<30);
}

int main(){
    int t, n, m; cin >> t;
    while(t-- && cin >> n >> m){
        int n, m, secondmst = (1<<30);
        vector<iii> edge(m); inmst.assign(m, false);
        for(int i = 0; i < m; i++)
            cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
        sort(edge.begin(), edge.end());
        cout << mst(edge, n, -1, true) << ' ';
        for(int i = 0; i < m; i++)
            if(inmst[i])
                secondmst = min(secondmst, mst(edge, n, i, false));
        cout << secondmst << endl;
    }
}