#include <iostream>
#include <map>

using namespace std;

map<long long, long long> memo;

long long digit_sum(long long x){
    if(memo[x] || x <= 0)
        return memo[x];

    long long tmp = x, pow10 = 1;

    while(x >= pow10*10){
        pow10 *= 10;
    }

    long long lead = x/pow10, tail = x%pow10, ans = 0;

    ans = lead*digit_sum(pow10-1) + digit_sum(lead-1)*pow10;
    ans += lead*(tail+1) + digit_sum(tail);

    return memo[x] = ans;
}

int main() {
    // single digit base case
    for(int i = 0; i < 10; i++){
        memo[i] = memo[i-1]+i;
    }

    int n;
    cin >> n;
    while(n--){
        long long a, b;
        cin >> a >> b;
        cout << digit_sum(b) - digit_sum(a-1) << endl;
    }

    return 0;
}