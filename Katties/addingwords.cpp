#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, int> mp;
map<int, string> rmp;
map<string, bool> def;

int main(){
    string opt, a, b;
    int x;
    bool unknown;
    while(cin >> opt){
        if(opt == "def"){
            cin >> a >> x;
            if(def[a]){
                rmp[mp[a]] = "";
            }
            mp[a] = x;
            rmp[x] = a;
            def[a] = true;
        }
        else if(opt == "calc"){
            unknown = false;
            cin >> a;
            cout << a << ' ';
            if(!def[a]) unknown = true;
            x = mp[a];
            while(cin >> b && b != "="){
                cin >> a;
                cout << b << ' ' << a << ' ';
                if(!def[a]) unknown = true;
                if(b == "+"){
                    x += mp[a];
                }
                else{
                    x -= mp[a];
                }
            }
            if(rmp[x].size() == 0) unknown = true;
            if(unknown){
                cout << "= unknown" << endl;
            }
            else{
                cout << "= " << rmp[x] << endl;
            }
        }
        else{
            mp.clear();
            rmp.clear();
            def.clear();
        }
    }

    return 0;
}