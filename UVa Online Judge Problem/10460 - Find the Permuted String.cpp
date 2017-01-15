#include <iostream>

using namespace std;

int position[100];

int main(){
    int t;
    cin >> t;

    while(t--){
        string s; int n;
        cin >> s >> n;

        n--;
        for(int i = s.size()-1; i >= 0; i--){
            position[i] = n%(i+1);
            n /= i+1;
        }

        string ans = "";
        for(int i = 0; i < s.size(); i++){
            string pre = ans; ans = "";
            int idx;
            for(idx = 0; idx < position[i]; idx++){
                ans += pre[idx];
            }
            ans += s[i];
            for(; idx < i; idx++){
                ans += pre[idx];
            }
        }

        cout << ans << endl;
    }

    return 0;
}