/*
ID: yunkai91
LANG: C++
TASK: runround
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool isrunround(int n){
    vector<int> a;
    int used[10] = {0};
    used[0] = 1;
    while(n > 0){
        if(used[n%10]) return false;
        used[n%10] = true;
        a.push_back(n%10);
        n /= 10;
    }

    a = vector<int> (a.rbegin(), a.rend());
    int pos = a[0]%a.size(), next;

    while(a[pos] != 0){
        next = (pos+a[pos])%a.size();
        a[pos] = 0;
        pos = next;
    }

    for(int i = 0; i < a.size(); i++){
        if(a[i] != 0) return false;
    }
    return true;

}

int main(){
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    int n;
    cin >> n;
    while(!isrunround(++n));
    cout << n << endl;

    return 0;
}