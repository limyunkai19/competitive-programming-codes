#include <iostream>
#include <cstdio>

using namespace std;

bool a[5][5];

bool check(){
    bool ans = true;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            if(a[i][j] == 1){
                ans = false;
            }
        }
    }
    return ans;
}

void toggle(int i, int j){
    a[i][j] ^= 1;
    a[i-1][j] ^= 1;
    a[i+1][j] ^= 1;
    a[i][j+1] ^= 1;
    a[i][j-1] ^= 1;
}

int step(int i, int j, int n){
    if(check()) return n;
    if(j == 4) return 10;

    int nexti, nextj;
    if(i == 3){
        nexti = 1;
        nextj = j+1;
    }
    else{
        nexti = i+1;
        nextj = j;
    }
    int minans = step(nexti, nextj, n);
    toggle(i, j);
    minans = min(minans, step(nexti, nextj, n+1));
    toggle(i, j);

    return minans;
}

int main(){
    int n;
    char x;
    cin >> n;
    while(n--){
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                cin >> x;
                a[i][j] = (x=='*'); // * = 1
            }
        }
        cout << step(1, 1, 0) << endl;
    }


    return 0;
}