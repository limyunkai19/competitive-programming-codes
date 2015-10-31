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

void count_fac(int n){
    if(n <= Min){
        return;
    }
    else{
        count_fac(n-1);
        fac[n] = fac[n-1];
        int carry = 0;
        for(int i = 0; i < fac[n].size(); i++){
            fac[n][i] *= n;
            fac[n][i] += carry;
            carry = fac[n][i]/10;
            fac[n][i] %= 10;
        }
        while(carry > 0){
            fac[n].push_back(carry%10);
            carry /= 10;
        }
        Min = n;


    }
}

int main()
{
    fac.assign(1010, vector<int> () );
    fac[0].push_back(1);
    int n;
    while(cin >> n){
        count_fac(n);
        cout << n << "!" << endl;
        printv(fac[n]);
    }
    return 0;
}
