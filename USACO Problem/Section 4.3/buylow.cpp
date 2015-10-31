/*
ID: yunkai91
LANG: C++
TASK: buylow
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void print(vector<int> &a){
    for(int i = a.size()-1; i >= 0; i--){
        cout << a[i];
    }
}

void plus_equal(vector<int> &a, vector<int> &b){
    // a += b;
    for(int i = 0; i < b.size(); i++){
        if(a.size() == i){
            a.push_back(b[i]);
        }
        else{
            a[i] += b[i];
            int carry = a[i]/10;
            a[i] %= 10;
            if(carry > 0){
                if(i+1 == a.size()){
                    a.push_back(carry);
                }
                else{
                    a[i+1] += carry;
                }
            }
        }
    }
    while(a[a.size()-1] > 10){
        int carry = a[a.size()-1]/10;
        a[a.size()-1] %= 10;
        a.push_back(carry);
    }
}

int main(){
    freopen("buylow.in", "r", stdin);
    freopen("buylow.out", "w", stdout);

    int n, x = 1, a[5010], lds[5010];
    vector<int> way[5010], count(1, 0);
    map<int, bool> used;
    cin >> n;
    cin >> a[0];
    way[0].push_back(1);
    lds[0] = 1;
    for(int i = 1; i < n; i++){
        cin >> a[i];
        lds[i] = 1;
        way[i].push_back(1);
        for(int j = i-1; j >= 0; j--){
            if(a[j] > a[i] && lds[j]+1 > lds[i]){
                lds[i] = lds[j]+1;
                way[i] = way[j];
                used.clear();
                used[a[j]] = true;
            }
            else if(a[j] > a[i] && lds[j]+1 == lds[i] && !used[a[j]]){
                plus_equal(way[i], way[j]);
                used[a[j]] = true;
            }
        }
        x = max(x, lds[i]);
    }
    used.clear();
    for(int i = n-1; i >= 0; i--){
        if(lds[i] == x && !used[a[i]]){
            plus_equal(count, way[i]);
            used[a[i]] = true;
        }
    }
    cout << x << ' ';
    print(count);
    cout << endl;
    return 0;
}
