#include <iostream>

using namespace std;

int a[30], sum, ans, n;

void backtrack(int i, int x){
    if(x > sum/2) return;

    if(x > ans){
        ans = x;
    }

    if(i == n) return;

    backtrack(i+1, x);
    backtrack(i+1, x+a[i]);
}

int main(){
    while(cin >> n && n != 0){
        sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        ans = 0;
        backtrack(0, 0);
        cout << sum-ans << ' ' << ans << endl;
    }
    return 0;
}