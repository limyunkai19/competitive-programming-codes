#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

typedef pair<double, int> di;

double x[1010], y[1010];

double distS(int i, int j){
    return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }

        priority_queue<di, vector<di>, greater<di> > pq;
        pq.push(di(0, 0));
        double mst = 0;
        vector<bool> visited(n, false);

        while(!pq.empty()){
            double edge = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(!visited[u]){
                visited[u] = true;
                mst += sqrt(edge);

                for(int i = 0; i < n; i++){
                    if(!visited[i]){
                        pq.push(di(distS(u, i), i));
                    }
                }
            }

        }

        printf("%0.2lf\n", mst);
        if(t != 0) printf("\n");
    }

    return 0;
}
