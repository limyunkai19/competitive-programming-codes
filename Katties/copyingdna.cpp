#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define INF 10000000

set<long long> hashes;
string ori, target;
vector<int> dp;
int mask;

bool find(long long target_hash, int state, int length){
    for(int i = 0; i < target.size(); i++){
        if(state & 1<<i){
            long long rolling_hash = 0;
            for(int j = i; j < target.size() && (state & 1<<j); j++){
                // try i-j segment
                rolling_hash = (rolling_hash*5) + target[j]-'0';

                if(rolling_hash == target_hash){
                    return true;
                }
            }
            rolling_hash = 0;
            for(int j = i; j >= 0 && (state & 1<<j); j--){
                // try i-j segment
                rolling_hash = (rolling_hash*5) + target[j]-'0';

                if(rolling_hash == target_hash){
                    return true;
                }
            }
        }
    }
    return false;
}

int solve(int state){
    //cout << state << ' ' << dp[state] << endl;
    if(dp[state] != -1)
        return dp[state];

    int ans = INF;
    for(int i = 0; i < target.size(); i++){
        if(state & 1<<i){
            long long rolling_hash = 0;
            int next_state = state;
            for(int j = i; j < target.size() && (state & 1<<j); j++){
                // try remove i-j segment
                rolling_hash *= 5;
                rolling_hash += target[j]-'0';
                next_state &= mask&~(1<<j);

                if(hashes.count(rolling_hash))
                    ans = min(ans, 1+solve(next_state));
                else if(find(rolling_hash, next_state, j-i+1))
                    ans = min(ans, 1+solve(next_state));
                else
                    break;

                if(ans == 1)
                    return dp[state] = ans;

            }
        }
    }

    return dp[state] = ans;
}

void transform(string& x){
    for(int i = 0; i < x.size(); i++){
        if(x[i] == 'A') x[i] = '1';
        if(x[i] == 'C') x[i] = '2';
        if(x[i] == 'G') x[i] = '3';
        if(x[i] == 'T') x[i] = '4';
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> ori >> target;
        transform(ori); transform(target);
        mask = (1<<target.size())-1;
        dp.assign(mask+1, -1);
        dp[0] = 0; // base case

        // procompute hashes;
        hashes.clear();
        for(int i = 0; i < ori.size(); i++){
            long long rolling_hash = 0;
            for(int j = i; j < ori.size(); j++){
                rolling_hash = rolling_hash*5 + ori[j]-'0';

                hashes.insert(rolling_hash);
            }
            long long backward_hash = 0;
            for(int j = i; j >= 0; j--){
                backward_hash = backward_hash*5 + ori[j]-'0';

                hashes.insert(backward_hash);
            }
        }
        int ans = solve(mask);
        if(ans == INF)
            cout << "impossible" << endl;
        else
            cout << ans << endl;
    }


    return 0;
}