/*
ID: yunkai91
LANG: C++
TASK: rockers
*/

#include <iostream>
#include <cstdio>

using namespace std;

int n, cap, m, song[50], maxsong = 0;

void findans(int idx, int capleft, int disk, int usedsong){
    if(idx == n){
        maxsong = max(usedsong, maxsong);
        return;
    }

    // try take this song
    if(song[idx] <= capleft){
        findans(idx+1, capleft-song[idx], disk, usedsong+1);
    }
    else if(disk != 1 && cap >= song[idx]){
        findans(idx+1, cap-song[idx], disk-1, usedsong+1);
    }

    findans(idx+1, capleft, disk, usedsong);
}

int main(){
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);

    cin >> n >> cap >> m;
    for(int i = 0; i < n; i++){
        cin >> song[i];
    }
    findans(0, cap, m, 0);
    cout << maxsong << endl;
    return 0;
}