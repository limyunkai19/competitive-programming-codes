/*
ID: yunkai91
LANG: C++
TASK: money
*/

#include <iostream>
#include <cstdio>

using namespace std;

long long ways[10100];

int main(){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    int v, target, x;
    cin >> v >> target;

    ways[0] = 1;
    for(int i = 0; i < v; i++){
        cin >> x;
        for(int j = x; j <= target; j++){
            ways[j] += ways[j-x];
        }
    }

    cout << ways[target] << endl;


    return 0;
}
