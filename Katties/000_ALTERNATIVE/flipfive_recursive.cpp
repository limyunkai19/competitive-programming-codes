#include <iostream>
#include <cstdio>

using namespace std;

string state, goal = "_________";
int ans;

void toggle(int cell){
    int a[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            a[i][j] = 0;
        }
    }
    int x = cell%3 + 1, y = cell/3 + 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i+1][j+1] = (state[i+j*3]=='*');
            // 1 -> *, 0 -> .
        }
    }
    a[x][y] ^= 1;
    a[x+1][y] ^= 1;
    a[x-1][y] ^= 1;
    a[x][y-1] ^= 1;
    a[x][y+1] ^= 1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            state[i+j*3] = a[i+1][j+1]?'*':'.';
            // 1 -> *, 0 -> .
        }
    }
}

void findstep(int cell, int n){
    if(cell == 9){
        if(state == goal)
            ans = min(ans, n);
        return;
    }

    findstep(cell+1, n);
    toggle(cell);
    findstep(cell+1, n+1);
    toggle(cell);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        for(int i = 0; i < 9; i++){
            cin >> goal[i];
        }
        ans = 10000000;
        state = ".........";
        findstep(0, 0);
        cout << ans << endl;
    }

    return 0;
}