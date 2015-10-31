/*
ID: yunkai91
LANG: C++
TASK: frac1
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

vector<ii> frac;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool cmp(ii a, ii b){
    return a.first*b.second < b.first*a.second;
}

int main(){
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    int n;
    cin >> n;
    frac.push_back(ii(0, 1));
    frac.push_back(ii(1, 1));

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(gcd(i, j) == 1){
                frac.push_back(ii(j, i));
            }
        }
    }

    sort(frac.begin(), frac.end(), cmp);

    for(int i = 0; i < frac.size(); i++){
        cout << frac[i].first << '/' << frac[i].second << endl;
    }

    return 0;
}