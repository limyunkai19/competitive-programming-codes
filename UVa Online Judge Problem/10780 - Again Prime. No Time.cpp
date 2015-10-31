#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

bitset<5010> bs;
vector<int> prime;
int MAX = 5003;
const int INF = 2000000000;

void sieve(){
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);
    for(int i = 0; i <= MAX; i++){
        if(bs.test(i)){
            for(int j = i*i; j < MAX; j+=i){
                bs.set(j, false);
            }
            prime.push_back(i);
        }
    }
}

vii prime_factorization(int m){
    int idx = 0;
    vii result; int count;
    while(true){
        if(m%prime[idx] == 0){
            count = 0;
            while(m%prime[idx] == 0){
                m/=prime[idx];
                count++;
            }
            result.push_back(ii(prime[idx], count));
        }
        if(m == 1){break;}
        else if(m < prime[idx]*prime[idx]){
            result.push_back(ii(m, 1));
            break;
        }
        idx++;
    }
    return result;
}

void print_primefac(vii PF){
    for(int i = 0; i < PF.size(); i++){
        if(i){
            printf(" * %d^%d", PF[i].first, PF[i].second);
        }
        else{
            printf("%d^%d", PF[i].first, PF[i].second);
        }
    }
    printf("\n");
}

int max_power(int p, int n){
    int idx = p, ans =0;
    while(idx <= n){
        ans += n/idx;
        idx *= p;
    }
    return ans;
}

int main()
{
    sieve();
    int m, n, power, min_power, tc, pm;
    vii result;
    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++){
        scanf("%d %d", &m, &n);
        min_power = INF;
        result = prime_factorization(m);
        for(int i = 0; i < result.size(); i++){
            min_power = min(min_power, max_power(result[i].first, n)/result[i].second);
        }
        printf("Case %d:\n", i);
        if(min_power > 0){
            printf("%d\n", min_power);
        }
        else{
            printf("Impossible to divide\n");
        }
    }

    return 0;
}
