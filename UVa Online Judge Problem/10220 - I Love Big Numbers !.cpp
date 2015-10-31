#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > Factorial;
vector<int> Fac_n(1, 0);
int sum[1001];

int Sum_of_Digit(vector<int> Fac){
    int sum = 0;
    for(int i = Fac.size() - 1; i > 0; i--){
        sum += Fac[i];
    }
    return sum;
}

vector<int> Big_Fac(int n){
    if(Factorial[n][0] > 0){return Factorial[n];}
    else{
        vector<int> pre = Big_Fac(n-1);
        int carry = 0;
        for(int i = 1; i < pre.size(); i++){
            pre[i] *= n;
            pre[i] += carry%10;
            carry /= 10;
            carry += pre[i]/10;
            pre[i] %= 10;
        }
        while(carry > 0){
            pre.push_back(carry%10);
            carry /= 10;
        }
        return Factorial[n] = pre;
    }
}

int main()
{
    Factorial.assign(1001, Fac_n);
    Factorial[0][0] = 1;
    Factorial[1][0] = 1;
    Factorial[0].push_back(0);
    Factorial[1].push_back(1);
    memset(sum, -1, sizeof sum);
    int n;
    while(cin >> n){
        cout << Sum_of_Digit(Big_Fac(n)) << endl;
    }
    return 0;
}
