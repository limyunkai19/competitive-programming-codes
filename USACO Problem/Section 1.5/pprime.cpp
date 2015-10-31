/*
ID: yunkai91
LANG: C++
TASK: pprime
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool isprime(int n){
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i = 3; i*i <= n; i+=2){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    freopen("pprime.out", "w", stdout);
    freopen("pprime.in", "r", stdin);

    int palindrome, x, y;
    vector<int> ans;

    cin >> x >> y;

    for(int a = 0; a <= 9; a++) for(int b = 0; b <= 9; b++)
    for(int c = 0; c <= 9; c++) for(int d = 0; d <= 9; d++)
    {
        for(int e = 0; e <= 9; e++)
        {
            palindrome = a + b*10 + c*100 + d*1000 + e*10000 + d*(1e5) + c*(1e6) + b*(1e7) + a*(1e8);
            while(palindrome%10 == 0 && palindrome > 0) palindrome /= 10;
            if(palindrome >= x && palindrome <= y && isprime(palindrome)) ans.push_back(palindrome);

        }
        palindrome = a + b*10 + c*100 + d*1000 + d*(1e4) + c*(1e5) + b*(1e6) + a*(1e7);
        while(palindrome%10 == 0 && palindrome > 0) palindrome /= 10;
        if(palindrome >= x && palindrome <= y && isprime(palindrome)) ans.push_back(palindrome);
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }


    return 0;
}