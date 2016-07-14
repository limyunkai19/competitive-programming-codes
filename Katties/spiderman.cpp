#include <iostream>
#include <cstring>

using namespace std;

char dp[50][1010];
int step[50], m;

string possible(int height){
    memset(dp, 0, sizeof dp);

    dp[0][step[0]] = 'U';
    for(int i = 1; i < m; i++){
        int x = step[i];
        for(int j = height; j >= 0; j--){
            if(dp[i-1][j] != 0){
                if(j+x <= height){
                    dp[i][j+x] = 'U';
                }
                if(j-x >= 0){
                    dp[i][j-x] = 'D';
                }
            }
        }
    }
    if(dp[m-1][0] == 0){
        return "IMPOSSIBLE";
    }
    else{
        int cur = 0;
        string ans = "";
        for(int i = m-1; i >= 0; i--){
            ans += dp[i][cur];
            cur += (dp[i][cur]=='D'?step[i]:-step[i]);
        }
        return string(ans.rbegin(), ans.rend());
    }

}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m;
        int a = 0, b = 0, mid = 500, ans = 1000;
        for(int i = 0; i < m; i++){
            cin >> step[i];
            b += step[i];
        }

        b /= 2;

        while(a <= b){
            mid = (a+b)/2;
            if(possible(mid) != "IMPOSSIBLE"){
                ans = mid;
                b = mid-1;
            }
            else{
                a = mid+1;
            }
        }
        cout << possible(ans) << endl;
    }

    return 0;
}