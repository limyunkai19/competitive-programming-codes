#include <iostream>

using namespace std;

#define INF 1000000000000000000

int parity[2][2], num[2010][2010], ori[2010][2010];
int r, c;

bool check(int i, int j){
    if(num[i][j]%2 != parity[i%2][j%2])
        return false;
    if(num[i][j] <= num[i-1][j])
        return false;
    if(num[i][j] <= num[i][j-1])
        return false;
    return true;
}


long long solve(){
    long long sum = 0;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(num[i][j] != 0){
                if(!check(i, j))
                    return INF;
            }
            else{
                num[i][j] = max(num[i-1][j], num[i][j-1])+1;
                if(num[i][j]%2 != parity[i%2][j%2])
                    num[i][j]++;
            }
            sum += num[i][j];
        }
    }

    return sum;

}

int main(){
    cin >> r >> c;

    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin >> ori[i][j];

    // OOOOOOOOMMMMMMMMMGGGGGGGG FAILED TO NOTICED THIS SPECIAL CASE
    if(r == 1){
        int sum = 0;
        for(int i = 1; i <= c; i++){
            if(ori[1][i] == 0)
                ori[1][i] = ori[1][i-1]+1;
            else if(ori[1][i] <= ori[1][i-1]){
                cout << -1 << endl;
                return 0;
            }
            sum += ori[1][i];
        }
        cout << sum << endl;
        return 0;
    }
    if(c == 1){
        int sum = 0;
        for(int i = 1; i <= r; i++){
            if(ori[i][1] == 0)
                ori[i][1] = ori[i-1][1]+1;
            else if(ori[i][1] <= ori[i-1][1]){
                cout << -1 << endl;
                return 0;
            }
            sum += ori[i][1];
        }
        cout << sum << endl;
        return 0;
    }

    long long ans = INF;

    // check all possible parity
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            parity[0][0] = i;
            parity[1][1] = (i+1)%2;
            parity[0][1] = j;
            parity[1][0] = (j+1)%2;

            for(int k = 1; k <= r; k++) for(int l = 1; l <= c; l++) num[k][l] = ori[k][l];

            ans = min(ans, solve());

            // for(int k = 1; k <= r; k++) {
            //     for(int l = 1; l <= c; l++) {
            //         cout << num[k][l] << ' ' ;
            //     }
            //     cout << endl;
            // }
        }
    }

    cout << (ans==INF?-1:ans) << endl;

    return 0;
}