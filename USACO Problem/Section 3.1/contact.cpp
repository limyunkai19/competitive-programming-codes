/*
ID: yunkai91
LANG: C++
TASK: contact
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    return a < b;
}

int main(){
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);

    int a, b, n;
    cin >> a >> b >> n;
    string s = "", x;
    while(cin >> x) s += x;
    map<string, int> fre;

    for(int len = a; len <= b; len++){
        for(int i = 0; i <= (int)s.size()-len; i++){
            x = "";
            for(int j = 0; j < len; j++){
                x += s[i+j];
            }
            fre[x]++;
        }
    }
    vector<string> ans;
    int maxfre;
    while(n--){
        maxfre = 1;
        ans.clear();
        for(map<string, int>::iterator it = fre.begin(); it != fre.end(); it++){
            if(it->second == maxfre){
                ans.push_back(it->first);
            }
            else if(it->second > maxfre){
                ans.clear();
                maxfre = it->second;
                ans.push_back(it->first);
            }
        }
        if(ans.size() == 0) break;
        cout << maxfre << endl;
        sort(ans.begin(), ans.end(), cmp);
        for(int i = 0; i < ans.size(); i++){
            if(i%6 == 0 && i) cout << endl;
            else if(i)cout << ' ';
            cout << ans[i];
            fre[ans[i]] = 0;
        }
        cout << endl;
    }

    return 0;
}