#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIMIT 30010

int dp[LIMIT+10], parent[LIMIT+10], a[110];

int main(){
    dp[0] = 1;

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = 0; j+a[i] <= LIMIT; j++){
            if(dp[j]){
                dp[j+a[i]] += dp[j];
                parent[j+a[i]] = i;
            }
        }
    }

    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(dp[x] == 0){
            cout << "Impossible" << endl;
        }
        else if(dp[x] != 1){
            cout << "Ambiguous" << endl;
        }
        else{
            vector<int> ans;
            while(x != 0){
                ans.push_back(parent[x]);
                x -= a[parent[x]];
            }
            for(int i = ans.size()-1; i >= 0; i--){
                cout << ans[i] << ' ' ;
            }
            cout << endl;
        }
    }


    return 0;
}