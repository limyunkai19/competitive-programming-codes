#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<double, int> di;

double dist[120][120];
double xpos[120], ypos[120];
int n;

double line_dist(int i, int j){
    return sqrt(  (xpos[i]-xpos[j])*(xpos[i]-xpos[j]) + (ypos[i]-ypos[j])*(ypos[i]-ypos[j]) );
}

double cannonfire(int i, int j){
    double len = line_dist(i, j);
    len -= 50;
    return abs((len/5))+2;
}

int main(){
    double x, y;
    cin >> xpos[0] >> ypos[0];
    cin >> x >> y;
    cin >> n;
    xpos[n+1] = x;
    ypos[n+1] = y;
    dist[0][n+1] = dist[n+1][0] = line_dist(0, n+1)/5;
    for(int i = 1; i <= n; i++){
        cin >> xpos[i] >> ypos[i];
        dist[0][i] = (line_dist(0, i)/5+2);
        dist[i][0] = (cannonfire(i, 0)-2);
        dist[i][n+1] = (cannonfire(i, n+1)-2);
        dist[n+1][i] = (line_dist(n+1, i)/5+2);
        dist[i][i] = 1e80;
        for(int j = 1; j < i; j++){
            dist[i][j] = dist[j][i] = cannonfire(i, j);
        }
    }


    priority_queue<di, vector<di>, greater<di> > pq;
    pq.push(di(0, 0));
    vector<double> shortest(120, 1e80);
    shortest[0] = 0;
    while(!pq.empty()){
        double w = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if( abs(w-shortest[idx]) > 0.0000001) continue;
        //cout << w << ' ' << idx << endl;
        for(int i = 1; i <= n+1; i++){
            if(shortest[i] > shortest[idx]+dist[idx][i]){
                shortest[i] = shortest[idx]+dist[idx][i];
                //cout << "Push: " << shortest[i] << ' ' << i << endl;
                pq.push(di(shortest[i], i));
            }
        }
    }
    cout.precision(10);
    cout << shortest[n+1] << endl;
}