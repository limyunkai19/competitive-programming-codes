/*
ID: yunkai91
LANG: C++
TASK: ttwo
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
char map[12][12];

void nextmove(int& x, int& y, int& d){
    if(map[x+di[d]][y+dj[d]] == '*'){
        d++;
        d %= 4;
        return;
    }
    else{
        x += di[d];
        y += dj[d];
        return;
    }
}

int main(){
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

    memset(map, '*', sizeof map);

    int cx, cy, cd = 3, fx, fy, fd = 3;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cin >> map[i][j];
            if(map[i][j] == 'F'){
                fx = i; fy = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'C'){
                cx = i; cy = j;
                map[i][j] = '.';
            }
        }
    }
    for(int move = 0; move < 40000000; move++){
        nextmove(fx, fy, fd);
        nextmove(cx, cy, cd);
        if(fx == cx && fy == cy){
            cout << move+1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}