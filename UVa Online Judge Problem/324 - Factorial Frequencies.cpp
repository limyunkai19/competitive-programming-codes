#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int> > fac;
int Min = 0;

void printv(vector<int> v){
    for(int i = v.size()-1; i >= 0; i--){
        cout << v[i];
    }
    cout << endl;
}

vector<int> count_dig(int n){
    vector<int> ans(10, 0);
    if(n <= Min){
        for(int i = 0; i < fac[n].size(); i++){
            ans[fac[n][i]]++;
        }
        return ans;
    }
    else{
        count_dig(n-1);
        fac[n] = fac[n-1];
        int carry = 0;
        for(int i = 0; i < fac[n].size(); i++){
            fac[n][i] *= n;
            fac[n][i] += carry;
            carry = fac[n][i]/10;
            fac[n][i] %= 10;
            ans[fac[n][i]]++;
        }
        while(carry > 0){
            fac[n].push_back(carry%10);
            ans[carry%10]++;
            carry /= 10;
        }
        Min = n;

        return ans;
    }
}


int main()
{
    fac.assign(1010, vector<int> () );
    fac[0].push_back(1);
    vector<int> digit;
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        digit = count_dig(n);
        printf("%d! --\n   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",
               n, digit[0], digit[1], digit[2], digit[3], digit[4], digit[5], digit[6], digit[7], digit[8], digit[9]);
    }
    return 0;
}
