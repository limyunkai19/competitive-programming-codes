#include <iostream>

using namespace std;

int profit[100100];

int main(){
    int n, money;
    cin >> n >> money;

    for(int i = 0; i < n; i++){
        cin >> profit[i];
        profit[i] -= money;
    }

    int ans = 0, cur = 0;

    for(int i = 0; i < n; i++){
        cur += profit[i];
        if(cur < 0)
            cur = 0;
        ans = max(cur, ans);
    }

    cout << ans << endl;

    return 0;
}