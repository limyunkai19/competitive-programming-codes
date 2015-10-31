#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

const int MAX = 3000000;

vector<int> prime;
bitset<3000000> bs;

void sieve(){
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, false);
    for(long long i = 2; i < MAX; i++){
        if(bs.test(i)){
            for(long long j = i*i; j < MAX; j+=i){
                bs.set(j, false);
            }
            prime.push_back( (int)(i) );
        }
    }
}

bool is_prime(int n){
    if(n <= 0){
        return false;
    }
    else{
        return bs.test(n);
    }
}

int main()
{
    sieve();
    int max_a, max_b, max_p = 0;
    for(int a = -999; a < 1000; a++){
        //cout << a << endl;
        for(int b = 1; b < 1000; b++){
            for(int i = 0; i <= b; i++){
                if(!is_prime(i*i + a*i + b)){
                    if(i > max_p){
                        max_p = i;
                        max_a = a;
                        max_b = b;
                    }
                    break;
                }
            }
        }
    }
    cout << max_a << " " << max_b << endl << max_a*max_b << endl;

    return 0;
}
