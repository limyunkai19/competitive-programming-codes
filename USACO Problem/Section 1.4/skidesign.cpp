/*
ID: yunkai91
LANG: C++
TASK: skidesign
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    int n, a[1010], mincost = 0, cost;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mincost += a[i]*a[i];
    }

    for(int mina = 0, maxa = 17; mina <= 100; mina++, maxa++){
        cost = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < mina){
                cost += (mina-a[i])*(mina-a[i]);
            }
            else if(a[i] > maxa){
                cost += (a[i]-maxa)*(a[i]-maxa);
            }
        }

        mincost = min(mincost, cost);
    }
    cout << mincost << endl;
}