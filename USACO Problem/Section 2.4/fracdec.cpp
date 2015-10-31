/*
ID: yunkai91
LANG: C++
TASK: fracdec
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int visited[100100];
vector<int> digit;

int main(){
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);

    int n, d, cnt = 1;
    cin >> n >> d;
    cout << n/d << '.';
    int tmp = n/d;
    if(tmp == 0) cnt++;
    while(tmp > 0){
        cnt++;
        tmp /= 10;
    }
    n %= d;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    int idx = 1;
    while(!visited[n]){
        visited[n] = idx++;
        n *= 10;
        digit.push_back(n/d);
        n %= d;
    }

    for(int i = 0; i < digit.size() && i != visited[0]-1; i++){
        if(i == visited[n]-1){
            if(cnt%76 == 0) cout << endl;
            cout << '('; cnt++;
        }
        if(cnt%76 == 0) cout << endl;
        cout << digit[i];
        cnt++;
    }
    if(!visited[0]){
        if(cnt%76 == 0) cout << endl;
        cout << ')';
    }
    cout << endl;

    return 0;
}
