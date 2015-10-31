/*
ID: yunkai91
LANG: C++
TASK: holstein
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int vitamin[50], v, n, feed[50][50], gain[50], ans[50], isfeed[50], minfeed = 50;

void findans(int num, int feednum){
    // check if valid
    bool valid = true;
    for(int i = 0; i < v; i++){
        if(gain[i] < vitamin[i]){
            valid = false;
            break;
        }
    }
    if(valid){
        if(feednum < minfeed){
            minfeed = feednum;
            memcpy(ans, isfeed, sizeof isfeed);
        }
        return;
    }
    if(num == n) return;

    isfeed[num] = 1;
    for(int i = 0; i < v; i++){
        gain[i] += feed[num][i];
    }
    findans(num+1, feednum+1);
    isfeed[num] = 0;
    for(int i = 0; i < v; i++){
        gain[i] -= feed[num][i];
    }
    findans(num+1, feednum);
}

int main(){
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    cin >> v;
    for(int i = 0; i < v; i++){
        cin >> vitamin[i];
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < v; j++){
            cin >> feed[i][j];
        }
    }

    findans(0, 0);
    cout << minfeed;
    for(int i = 0; i < n; i++){
        if(ans[i]){
            cout << ' ' << i+1;
        }
    }
    cout << endl;
    return 0;
}