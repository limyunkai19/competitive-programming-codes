#include <iostream>

using namespace std;

int n, a[20], dp[1<<17], visited[1<<17];

int switch_bit(int state, int bit){
    if(state & 1<<bit){
        // it is a 1, need change to 0
        return ~(switch_bit(~state, bit));
    }
    else{
        // it is a 0, need change to 1
        return (state | 1<<bit);
    }
}

int solve(int state){
    cout << state << endl;
    visited[state] = true;
    if(dp[state] != 0)
        return dp[state];
    if(state == 0)
        return 0;

    int cloth_pos = state%2;
    int min_time = 1<<30;
    for(int i = 1; i <= n; i++){
        //      1               1                  0                 0
        if((cloth_pos && (state & 1<<i)) || (!cloth_pos && (~state & 1<<i)) ){
            // for each person, try go alone
            int next_state = switch_bit(state, 0);
            next_state = switch_bit(next_state, i);
            if(!visited[next_state])
                min_time = min(solve(next_state)+a[i], min_time);
            // now bring another person
            for(int j = i+1; j <= n; j++){
                if( (cloth_pos && (state & 1<<j)) || (!cloth_pos && (~state & 1<<j)) ){
                    int next_state2 = switch_bit(next_state, j);
                    if(!visited[next_state2])
                        min_time = min(solve(next_state2)+max(a[i], a[j]), min_time);
                }
            }
        }
    }
    return dp[state] = min_time;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cout << solve((1<<(n+1))-1) << endl;

    return 0;
}