/*
ID: yunkai91
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <cstdio>

using namespace std;

int n, x[20], y[20], paring[20], nexthole[20];

bool cycle(){
    for(int start = 1; start <= n; start++){
        int hole = start;
        for(int i = 0; i < 20; i++){
            hole = nexthole[paring[hole]];
        }
        if(hole != 0) return true;
    }
    return false;
}

int count(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(paring[i] == 0){
            for(int j = i+1; j <= n; j++){
                if(paring[j] == 0){
                    paring[i] = j;
                    paring[j] = i;
                    ans += count();
                    paring[i] = 0;
                    paring[j] = 0;
                }
            }
            break;
        }

        if(i == n){ // all paring
            if(cycle()) return 1;
            else return 0;
        }
    }
    return ans;
}

int main(){
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(y[j] == y[i] && x[j] > x[i]){
                if(nexthole[i] == 0 || x[nexthole[i]] > x[j]){
                    nexthole[i] = j;
                }
            }
        }
    }

    cout << count() << endl;

}