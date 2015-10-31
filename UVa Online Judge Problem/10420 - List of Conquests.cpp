#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> country;
    string name;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name;
        /*if(country.count(name) == 0){
            country[name] = 1;
        }
        else{
            country[name]++;
        }*/
        country[name]++;
        getline(cin, name);
        //cout << name << endl;
    }
    for(map<string, int>::iterator it = country.begin(); it != country.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
