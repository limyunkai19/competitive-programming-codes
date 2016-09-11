#include <iostream>
#include <cmath>

using namespace std;

long long n, r, p;
long long dp[1000100];
long long solve(long long i){
    if(i <= 1)
        return 0;
    if(dp[i] != 0)
        return dp[i];

    // linear search = printf each line then run once
    //int linear = p*(i-1) + r;

    // binary search = printf at middle then run then reduce half
    //int binary = p + r + solve((i+1)/2);

    // n-nary search = printf at n place then run then reduce n factor
    // when n = i-1, = linear search

    long long ans = 1LL<<61;
    for(int n_nary = 1; n_nary < i; n_nary++){
        ans = min(ans, p*n_nary + r + solve(ceil(i/(n_nary+1.0))));
    }


    return dp[i] = ans;
}

int main() {
    cin >> n >> r >> p;
    cout << solve(n) << endl;


    return 0;
}