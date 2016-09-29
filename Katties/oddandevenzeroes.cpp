#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> dp;
vector<long long> five;

int log5(long long n){
    return lower_bound(five.begin(), five.end(), n) - five.begin();
}

long long even_zeros(long long n, long long parity){
    if(dp[n] != 0){
        if(parity%2)
            return n + 1 - dp[n];
        else
            return dp[n];
    }

    // count even zero
    long long pow5 = *upper_bound(five.begin(), five.end(), n)/5;
    long long tmp = n, k = min(tmp, pow5);

    for(long long p = 0; tmp >= 0; p += log5(pow5)){
        if(tmp >= pow5){
            dp[n] += even_zeros(pow5-1, p);
        }
        else{
            dp[n] += even_zeros(tmp, p);
        }
        tmp -= pow5;
    }
    return even_zeros(n, parity);
}

int main(){
    for(int i = 0; i < 5; i++)
        dp[i] = i+1;

    long long pow5 = 1;
    five.push_back(1);
    while(pow5 < 6e18){
        pow5 *= 5;
        five.push_back(pow5);
    }

    long long n;
    while(cin >> n && n != -1){
        cout << even_zeros(n, 0) << endl;
    }

    return 0;
}