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
    //freopen("input.txt", "r", stdin);
    int tc, n;
    string name;
    map<string, int> popu;
    cin >> tc; getchar(); getchar();
    while(tc--){
        popu.clear();
        n = 0;
        if(tc){
            getline(cin, name);
            while(name.size() > 0){
                popu[name]++;
                n++;
                getline(cin, name);
            }
            for(map<string, int>::iterator it = popu.begin(); it != popu.end(); it++){
                printf("%s %0.4f\n", it->first.c_str(), 100.0*(it->second)/n);
            }
            printf("\n");
        }
        else{
            while(getline(cin, name)){
                popu[name]++;
                n++;
            }
            for(map<string, int>::iterator it = popu.begin(); it != popu.end(); it++){
                printf("%s %0.4f\n", it->first.c_str(), 100.0*(it->second)/n);
            }
        }
    }

    return 0;
}
