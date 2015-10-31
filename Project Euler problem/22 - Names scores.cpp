#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("names.txt", "r", stdin);
    freopen("sorted.txt", "w", stdout);
    char a;
    string b;
    vector<string> name;
    cin >> a;
    while(cin >> a){
        if(a != '"'){
            b += a;
        }
        else{
            name.push_back(b);
            b.clear();
            cin >> a;
            cin >> a;
        }
    }
    long long sum = 0, c;
    sort(name.begin(), name.end());
    for(int i = 0; i < name.size(); i++){
        cout << i << ": " << name[i] << endl;
        c = 0;
        for(int j = 0; j < name[i].size(); j++){
            c += name[i][j] - 'A' + 1;
        }
        sum += c*(i+1);
    }
    cout << sum << endl;

    return 0;
}
