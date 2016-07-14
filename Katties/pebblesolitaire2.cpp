#include <iostream>
#include <cstring>

using namespace std;

int dp[1<<24], mask = 0;

int to_state(string s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans *= 2;
        ans += s[i]=='o';
    }
    return ans;
}


bool ith_bit(int x, int i){
    return (1<<i & x)!=0;
}

int solve(int state){
    if(dp[state] != -1)
        return dp[state];

    int remain = 0;
    for(int i = 0; i < 23; i++)
        remain += (1<<i & state)!=0;

    // try move right
    for(int i = 0; i < 21; i++){
        if(ith_bit(state, i) && ith_bit(state, i+1) && !ith_bit(state, i+2)){
            remain = min(remain, solve(mask&state&~(1<<i)&~(1<<(i+1))|(1<<(i+2))));
        }
    }

    // try move left
    for(int i = 2; i < 23; i++){
        if(ith_bit(state, i) && ith_bit(state, i-1) && !ith_bit(state, i-2)){
            remain = min(remain, solve(mask&state&~(1<<i)&~(1<<(i-1))|(1<<(i-2))));
        }
    }

    return dp[state] = remain;
}

int main(){
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 23; i++){
        mask += 1<<i;
    }

    string x;
    int n;
    cin >> n;
    while(n--){
        cin >> x;
        cout << solve(to_state(x)) << endl;
    }

    return 0;
}