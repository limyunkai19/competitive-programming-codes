#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int limit;
short winning[2010][2010];
string s;

bool win(int n, int cake){
    if(winning[n][cake] != -1) return winning[n][cake];
    if(cake <= limit) return winning[n][cake] = 1;

    //eat 1 to K cake
    bool ans = 0;
    for(int i = min(limit, cake-1); i >= 1; i--){
        if((s[n] == s[n+1]) == win(n+1, cake-i)){
            ans = 1;
            break;
        }
    }

    return winning[n][cake] = ans;

}

int main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n, cake;
        cin >> n >> cake >> limit >> s;
        memset(winning, -1, sizeof winning);
        cout << "Case #" << tc << ": ";
        if(win(0, cake)){
            cout << s[0] << endl;
        }
        else{
            cout << ((s[0]=='A')?'B':'A') << endl;
        }
    }
    return 0;
}