#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool isvowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main(){
    string s, del = "";
    vector<char> a;
    while(cin >> s){
        a.clear();
        for(int i = 0; i < s.size(); i++){
            int sz = a.size();
            if(sz > 1 && a[sz-1] == 'p' && isvowel(s[i]) && a[sz-2] == s[i]){
                a.pop_back();
                a.pop_back();
                a.push_back(s[i]);
                a.push_back(s[i+1]);
                a.push_back(s[i+2]);
                i+=2;

                continue;
            }
            a.push_back(s[i]);
        }
        cout << del;
        for(int i = 0; i < a.size(); i++){
            cout << a[i];
        }
        del = " ";
    }

    return 0;
}