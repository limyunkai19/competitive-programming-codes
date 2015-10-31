/*
ID: yunkai91
LANG: C++
TASK: prefix
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool possible[200100];
vector<string> primitives;
int main(){
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    string a, x;
    while(cin >> a && a != "."){
        primitives.push_back(a);
    }
    cin >> a;
    while(cin >> x) a += x;

    possible[0] = true;
    for(int i = 0; i < a.size(); i++){
        if(possible[i]){
            for(int j = 0; j < primitives.size(); j++){
                // try fix this premitive;
                string b = primitives[j];
                int k;
                for(k = 0; k < b.size(); k++){
                    if(b[k] != a[i+k]) break;
                }
                if(k == b.size()){
                    possible[i+k] = true;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= a.size(); i++){
        if(possible[i]){
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}