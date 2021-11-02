// link: https://csacademy.com/ieeextreme-practice/task/summation/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> dp;
long long choose(int n, int k, int mod) {
    if(dp.size() <= n) {
        dp.resize(n+1, vector<int>(n+1, -1));
    }
    
    if(dp[n][k] != -1) {
        return dp[n][k];
    }
    
    if(k == 0 || k == n) {
        return dp[n][k] = 1;
    }
    
    return dp[n][k] = (choose(n-1, k-1, mod) + choose(n-1, k, mod)) % mod;
}

long long power(int base, int exponent, int mod) {
    if(exponent == 0) return 1;
    if(exponent == 1) return base;
    
    long long halfPower = power(base, exponent/2, mod);
    if(exponent % 2 == 0)
        return (halfPower * halfPower) % mod;
    return (((halfPower * halfPower) % mod) * base) % mod; 
}

unordered_map<int, vector<long long>> memo;
long long sum(long long p, long long q, long long n, long long mod) {
    // base case
    if(n == 0) return 0;
    if(n == 1) return p;
    
    // dp 
    if(memo.count(n) == 0) {
        memo[n].resize(q+1, -1);
    }
    
    auto& dp = memo[n];
    if(dp[q] != -1) {
        return dp[q];
    }
    
    // recurrence
    // ref: https://www.ijser.org/researchpaper/Some-algorithmic-methods-for-computing-the-sum-of-powers.pdf
    // ref: https://en.wikipedia.org/wiki/Binomial_theorem
    long long binomial = 0;
    for(int i = q; i >= 0; i--) {
        long long term = choose(q, i, mod) * power(n/2, q-i, mod);
        term = (term % mod) * sum(p, i, n/2, mod);
        binomial = (binomial + term) % mod;
    }
    
    // f(2n) = f(n) + p^n * binomial
    dp[q] = (sum(p, q, n/2, mod) + power(p, n/2, mod) * binomial) % mod;
    
    if(n % 2 == 1) {
        dp[q] = (dp[q] + power(p, n, mod) * power(n, q, mod)) % mod;
    }
    return dp[q];
}

int main() {
    int p, q, n, m;
    cin >> p >> q >> n >> m;
    cout << sum(p, q, n, m) << endl;
    return 0;
}
