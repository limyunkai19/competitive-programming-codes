#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

vector<int> prime;
const int MAX = 1e7;
bitset<10000005> bs;

void sieve(){
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, false);
    for(long long i = 2; i <= MAX; i++){
        if(bs.test(i)){
            for(long long j = i*i; j <= MAX; j+=i){
                bs.set(j, false);
            }
            prime.push_back( (int)(i) );
        }
    }
}

bool is_panta(int n){
    int used[10], dig = 0;
    memset(used, 0, sizeof used);
    while(n > 0){
        used[n%10]++;
        n /= 10;
        dig++;
    }
    for(int i = 1; i <= dig; i++){
        if(!used[i]){
            return false;
        }
    }
    return true;
}

bool is_prime(int n){
    if(n < MAX){
        return bs.test(n);
    }
    else{
        for(int i = 0; i < prime.size() && prime[i]*prime[i] <= n; i++){
            if(n % prime[i] == 0){
                return false;
            }
        }
        return true;
    }
}
int main()
{
    sieve();
    int num[10], a;
    bool sol = false;
    for(int dig = 9; dig > 0; dig--){
        for(int i = 1; i <= dig; i++){
            num[i-1] = i;
        }
        prev_permutation(num, num + dig);
        do{
            a = 0;
            for(int i = 0; i < dig; i++){
                a *= 10;
                a += num[i];
            }
            if(is_prime(a)){
                sol = true;
                cout << a << endl;
                break;
            }
        }
        while(prev_permutation(num, num + dig));
        if(sol){
            break;
        }
    }
    return 0;
}
