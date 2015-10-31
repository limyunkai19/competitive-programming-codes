#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<int, int> counter;
vector<int> ans;
vector<int>::iterator it;

int main()
{
    for(int i = 1; i*i*i < 1000100100; i++){
        for(int j = i; j*j*j < 1000100100; j++){
            if(counter[i*i*i + j*j*j] == 1){
                ans.push_back(i*i*i + j*j*j);
            }
            counter[i*i*i + j*j*j]++;
        }
    }
    sort(ans.begin(), ans.end());
    int a, b, r;
    while(cin >> a >> r){
        b = a+r;
        it = lower_bound(ans.begin(), ans.end(), a);
        if(*it > b){
            cout << "None\n";
        }
        while(*it <= b && it != ans.end()){
            cout << *it << "\n";
            it++;
        }
    }


    return 0;
}
