#include <iostream>
using namespace std;

string s;

string split(int x, int y){
    string tmp = "", ans = "";
    for(int i = 0; i < x; i++){
        tmp += s[i];
    }
    ans += string(tmp.rbegin(), tmp.rend());
    tmp = "";
    for(int i = x; i < y; i++){
        tmp += s[i];
    }
    ans += string(tmp.rbegin(), tmp.rend());
    tmp = "";
    for(int i = y; i < s.size(); i++){
        tmp += s[i];
    }
    ans += string(tmp.rbegin(), tmp.rend());
    return ans;
}

int main() {
    cin >> s;
    string x = "z";
    x[0] = 'z'+1;
    for(int i = 1; i <= s.size()-2; i++){
        for(int j = i+1; j <= s.size()-1; j++){
            x = min(x, split(i, j));
        }
    }
    cout << x << endl;

    return 0;
}