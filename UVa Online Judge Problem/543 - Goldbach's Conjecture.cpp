#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

typedef long long ll;

bitset<1000010> bs;
vector<int> prime;
int MAX = 1000000;

void sieve(){
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);
    for(ll i = 0; i < MAX; i++){
        if(bs.test(i)){
            for(ll j = i*i; j < MAX; j+=i){
                bs.set(j, false);
            }
            prime.push_back(int(i));
        }
    }
}

int main()
{
    sieve();
    int n, idx;
    scanf("%d", &n);
    while(n != 0){
        idx = 0;
        while(++idx){
            if(bs[n-prime[idx]]){
                printf("%d = %d + %d\n", n, prime[idx], n-prime[idx]);
                break;
            }
        }
        scanf("%d", &n);
    }
    return 0;
}
