/*
ID: yunkai91
LANG: C++
TASK: preface
*/

#include <iostream>
#include <cstdio>

using namespace std;

int used[4000][7] = {0};
    // 0 1 2 3 4 5 6
    // I V X L C D M

void add(int a, int b){
    for(int i = 0; i < 7; i++){
        used[b][i] += used[a][i];
    }
}

bool iszero(int a){
    for(int i = 0; i < 7; i++){
        if(used[a][i] != 0) return false;
    }
    return true;
}

int main(){
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    //             0, 1, 2, 3, 4, 5, 6, 7, 8
    int ones[9] = {0, 1, 2, 3, 1, 0, 1, 2, 3};
    int five[9] = {0, 0, 0, 0, 1, 1, 1, 1, 1};
    char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    int n;
    cin >> n;

    for(int i = 1; i <= 8; i++){
        used[i][0] = used[i*10][2] = used[i*100][4] = ones[i];
        used[i][1] = used[i*10][3] = used[i*100][5] = five[i];

        if(i < 4) used[i*1000][6] = ones[i];
    }

    used[9][0] = used[90][2] = used[900][4] = 1;
    used[9][2] = used[90][4] = used[900][6] = 1;

    int tmp;
    for(int i = 1; i <= n; i++){
        if(iszero(i)){
            tmp = i;
            for(int j = 1; i/j != 0; j *= 10){
                add(tmp%(j*10), i);
                tmp -= tmp%(j*10);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        add(i-1, i);
    }

    for(int i = 0; i < 7; i++){
        if(used[n][i] == 0) break;
        cout << roman[i] << ' ' << used[n][i] << endl;
    }

    return 0;
}