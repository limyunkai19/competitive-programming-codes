#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int mark[20], mask, dp[1<<11], n, m;
bool road[110];

int solve(int state){
    if(dp[state] != -1)
        return dp[state];

    int s;
    for(s = 0; ; s++){
        if(state & 1<<s)
            break;
    }
    int ans = solve(state&mask&~(1<<s))+1;

    for(int i = s+1; i < n; i++){
        if(state & 1<<i){
            // select i as second one
            int dist = mark[i]-mark[s];

            int next_state = state;
            bool possible = true;
            for(int now = mark[s]; now >= 0; now -= dist){
                if( !road[now] ){
                    possible = false;
                    break;
                }
            }
            for(int now = mark[s], j = s; now < m && possible; j++){
                if(!road[now]){
                    possible = false;
                    break;
                }
                if(mark[j] == now){
                    next_state &= mask&~(1<<j);
                    now += dist;
                }
            }
            if(possible)
                ans = min(ans, solve(next_state)+1);
        }
    }
    return dp[state] = ans;
}

int main(){
    while(cin >> m >> n){
        memset(road, 0, sizeof road);
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            cin >> mark[i];
            road[mark[i]] = true;
        }
        sort(mark, mark+n);

        mask = (1<<n) - 1;
        cout << solve(mask) << endl;
    }


    return 0;
}