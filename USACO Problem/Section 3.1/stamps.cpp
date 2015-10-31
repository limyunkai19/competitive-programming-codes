/*
ID: yunkai91
LANG: C++
TASK: stamps
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int minstamp[2000100], stamps[80];

int main(){
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

    int cap, n, smallest = 2;
    cin >> cap >> n;
    for(int i = 0; i < n; i++){
        cin >> stamps[i];
        smallest = min(smallest, stamps[i]);
    }

    if(smallest != 1){
        cout << 0 << endl;
        return 0;
    }
    int furthest = 1;
    minstamp[1] = 1;
    while(minstamp[furthest++] <= cap){
        minstamp[furthest] = cap+1;
        for(int i = 0; i < n; i++){
            if(stamps[i] > furthest) continue;
            minstamp[furthest] = min(minstamp[furthest], minstamp[furthest-stamps[i]]+1);
        }
    }
    cout << furthest-2 << endl;

    return 0;
}