#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

string s, x;

int frequency[30];
map<string, bool> tried;
short dp[250][250][250];

bool check_frequency(string x){
    int x_fre[30] = {0};

    for(int i = 0; i < x.size(); i++){
        x_fre[x[i]-'a']++;
    }

    int len = s.size()/x.size();

    for(int i = 0; i < 30; i++){
        if(x_fre[i]*len != frequency[i])
            return false;
    }
    return true;
}

// it is on right open interval, [s_l, s_r)
bool solve(int x_idx, int s_l, int s_r){
    x_idx %= x.size();
    // base case
    if(s_l == s_r)
        return x_idx == 0;
    if(dp[x_idx][s_l][s_r] != -1)
        return dp[x_idx][s_l][s_r] == 1;

    // invalid
    if(x[x_idx] != s[s_l])
        return dp[x_idx][s_l][s_r] = 0;

    // 0-n solvable string in between
    for(int i = 0; i < s.size(); i++){
        if(s_l+1+i*x.size() > s_r) break;
        if( solve(0, s_l+1, s_l+1+i*x.size()) && solve(x_idx+1, s_l+1+i*x.size(), s_r) ){
            return dp[x_idx][s_l][s_r] = 1;
        }
    }

    // no matched found
    return dp[x_idx][s_l][s_r] = 0;
}

bool try_string(string needle){
    if(tried[needle])
        return false;
    tried[needle] = true;

    x = needle;
    memset(dp, -1, sizeof dp);

    return solve(0, 0, s.size());
}

int main(){
    cin >> s;

    string ans = s;

    for(int i = 0; i < s.size(); i++){
        frequency[s[i]-'a']++;
    }

    for(int i = 0; i < s.size(); i++){
        string x = "";
        for(int j = i; j < s.size() && x.size() < ans.size(); j++){
            x += s[j];
            // all possible substring
            if(s.size() % x.size() != 0)
                continue;

            if(check_frequency(x) && try_string(x)){
                if(x.size() < ans.size() || x.size() == ans.size() && x < ans){
                    ans = x;
                }
            }
        }
    }
    cout << ans << endl;
}
