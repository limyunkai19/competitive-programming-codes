/*
ID: yunkai91
LANG: C++
TASK: inflate
*/

#include <iostream>
#include <cstdio>

using namespace std;

int maxscore[11000];

int main(){
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);

    int totaltime, cat, score, m;
    cin >> totaltime >> cat;
    while(cat--){
        cin >> score >> m;
        maxscore[m] = max(score, maxscore[m]);
        for(int i = m+1; i <= totaltime; i++){
            if(maxscore[i-m] == 0) continue;
            maxscore[i] = max(maxscore[i-m]+score, maxscore[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= totaltime; i++){
        ans = max(maxscore[i], ans);
    }
    cout << ans << endl;

    return 0;
}