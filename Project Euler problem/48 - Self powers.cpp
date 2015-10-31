#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> selfpower(int i){
    vector<int> ans(11, 0);
    ans[0] = 1;
    for(int j = 1; j<= i; j++){
        for(int k = 0; k < 11; k++){
            ans[k]*= i;
        }
        for(int k = 0; k < 10; k++){
            ans[k+1] += ans[k]/10;
            ans[k] %= 10;
        }
    }
    ans.pop_back();
    return ans;
}

int main()
{
    vector<int> ans(11, 0);
    vector<int> temp;
    int n = 1000;
    for(int i = 1; i <= n; i++){
        temp = selfpower(i);
        for(int k = 0; k < 10; k++){
            ans[k] += temp[k];
        }
    }
    for(int k = 0; k < 10; k++){
        ans[k+1] += ans[k]/10;
        ans[k] %= 10;
    }
    for(int i = 9; i >= 0; i--){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
