/*
ID: yunkai91
LANG: C++
TASK: subset
*/

#include <iostream>
#include <cstdio>

using namespace std;

long long ways[10000];

int main(){
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    int n;
    cin >> n;
    if(n%4 != 3 && n%4 != 0){
        cout << 0 << endl;
        return 0;
    }

    int maxsum = n*(n+1)/2;

    ways[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = maxsum; j >= i; j--){
            ways[j] += ways[j-i];
        }
    }

    cout << ways[maxsum/2]/2 << endl;

    return 0;
}