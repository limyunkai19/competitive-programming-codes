/*
ID: yunkai91
LANG: C++
TASK: cowtour
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int x[200], y[200];
string connected[200];
double dist[200][200];

double pointdist(int i, int j){
    int dx = x[i]-x[j], dy = y[i]-y[j];
    return sqrt(dx*dx+dy*dy);
}

int main(){
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        cin >> connected[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) dist[i][j] = 0;
            else if(connected[i][j] == '1') dist[i][j] = pointdist(i, j);
            else dist[i][j] = 1e30;
        }
    }

    for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
            dist[i][j] = dist[i][k] + dist[k][j];
        }
    }

    double mindia = 1e29;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] > 1e29){
                //try connect i, j;
                double fari = 0, farj = 0;
                for(int k = 0; k < n; k++){
                    if(dist[i][k] < 1e29) fari = max(fari, dist[i][k]);
                    if(dist[j][k] < 1e29) farj = max(farj, dist[j][k]);
                }
                mindia = min(mindia, fari+pointdist(i, j)+farj);
            }
        }
    }
    //in case the diameter of original graph is the largest
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] > 1e29) continue;
            mindia = max(mindia, dist[i][j]);
        }
    }
    printf("%0.6lf\n", mindia);

    return 0;
}
