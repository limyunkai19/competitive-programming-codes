#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int dp[200010];

int main(){
    int t;
    cin >> t;
    while(t--){
        int target, n, money;
        cin >> target >> n;

        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        while(n--){
            cin >> money;
            for(int i = 10000; i >= 0; i--){
                if(dp[i] != -1)
                    if(dp[i+money] == -1)
                        dp[i+money] = dp[i]+1;
                    else
                        dp[i+money] = min(dp[i+money], dp[i]+1);
            }
        }
        for(int i = target; i < 200000; i++){
            if(dp[i] != -1){
                cout << i << ' ' << dp[i] << endl;
                break;
            }
        }
    }

    return 0;
}