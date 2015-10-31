#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

bitset<10000007> bs;
vector<long long> primes;

void sieve(){
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, false);
    for(long long i = 2; i < 10000000; i++){
        if(bs.test(i)){
            for(long long j = i*i; j < 10000000; j+=i){
                bs.set(j, false);
            }
            primes.push_back(i);
        }
    }
}

bool prime(long long i){
    if(i < 10000000){
        return bs.test(i);
    }
    else{
        long long lim = sqrt(i) + 1;
        for(int a = 0; primes[a] <= lim && a < primes.size(); a++){
            if(i%primes[a] == 0){
                return false;
            }
        }
        return true;
    }
}

bool valid(long long i){
    long long a = i%10;
    if(!(a == 3 || a == 7)){
        return false;
    }
    while(i >= 10){
        a = i%10;
        i /= 10;
        if(!(a == 3 || a == 7 || a == 9 || a == 1)){
            return false;
        }
    }
    if(i == 3 || i == 5 || i == 7 || i == 2){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    freopen("out.txt", "w", stdout);
    long long sum = 0;
    sieve();
    long long count = 11, a, b, mul;
    bool sol;
    for(long long i = 11; count != 0 ; i+=2){
        if(valid(i) && prime(i)){
            //cout << i << endl;
            sol = true;
            a = i;
            mul = 1;
            while(a > 0){
                mul *= 10;
                if(!prime(a)){
                    //cout << "a: " << a << endl;
                    sol = false;
                    break;
                }
                a /= 10;
            }
            if(!sol){
                continue;
            }
            b = i;
            while(mul > 1){
                b %= mul;
                //cout << mul << endl;
                mul /= 10;
                if(!prime(b)){
                    //cout << "b: " << b << endl;
                    sol = false;
                    break;
                }
            }
            if(sol){
                cout << i << endl;
                sum += i;
                count--;
            }

        }
    }
    cout << sum << endl;

    return 0;
}
