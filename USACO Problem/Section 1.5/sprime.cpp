/*
ID: yunkai91
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> ans;

bool isprime(int x){
    if(x == 0 || x == 1) return false;
    if(x == 2) return true;
    if(x%2 == 0) return false;
    for(int i = 3; i*i <= x; i+=2){
        if(x%i == 0) return false;
    }
    return true;
}

void findprime(int left, int num){
    if(left == 0){
        ans.push_back(num);
        return;
    }

    for(int i = 1; i <= 9; i++){
        if(isprime(num*10+i)){
            findprime(left-1, num*10+i);
        }
    }
}

int main(){
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);


    cin >> n;
    findprime(n, 0);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}