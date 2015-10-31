#include <iostream>
#include <cstdio>

using namespace std;

int goal[5][5];

int main(){
    int n, ans;
    char x;
    cin >> n;
    while(n--){
        ans = 1000000;
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                cin >> x;
                if(x == '.')
                    goal[i][j] = 0;
                else
                    goal[i][j] = 1;
            }
        }
        for(int i = 0; i < (1<<9); i++){
            int state[5][5] = {0}, bit = 0;
            for(int j = 0; j < 9; j++){
                if(i&(1<<j)){
                    bit++;
                    int x = j%3+1, y = j/3+1;
                    //toggle cell x, y;
                    state[x][y] ^= 1;
                    state[x+1][y] ^= 1;
                    state[x-1][y] ^= 1;
                    state[x][y+1] ^= 1;
                    state[x][y-1] ^= 1;
                }
            }

            bool matched = true;
            for(int j = 1; j <= 3; j++){
                for(int k = 1; k <= 3; k++){
                    if(state[j][k] != goal[j][k]){
                        matched = false;
                    }
                }
            }

            if(matched){
                ans = min(ans, bit);
            }
        }
        cout << ans << endl;
    }
    return 0;
}