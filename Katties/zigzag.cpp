#include <iostream>

using namespace std;

int abs(int x){
    if(x < 0) return -x;
    return x;
}

int main(){
    int n;
    cin >> n;

    string ans = "a";

    while(n > 0){
        if(n >= 25){
            ans += (ans[ans.size()-1]=='a'?'z':'a');
            n -= 25;
        }
        else{
            for(int i = 25; i >= 0; i--){
                if(abs(ans[ans.size()-1]-'a'-i) == n){
                    ans += 'a'+i;
                    break;
                }
            }
            n = 0;
        }
    }
    if(ans.size() <= 2){
        cout << ans << endl;
    }
    else if(ans.size() == 3){
        while(ans[2] - 'a' >= 2){
            ans[1]--;
            ans[2] -= 2;
        }
        cout << ans << endl;
    }
    else{
        int last = ans.size()-1, diff;
        if(ans[last-1] == 'a'){
            diff = 2;
        }
        else{
            diff = -2;
        }

        while(ans[last]-'a' + diff < 26 && ans[last]-'a' + diff >= 0){
            ans[last] += diff;
            ans[1]--;
        }
        cout << ans << endl;
    }

    return 0;
}