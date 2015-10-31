#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

bitset<1000005> bs;
const int MAX = 1000000;

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
        }
    }
}

int main()
{
    sieve();
    int p, dig, m, num = 0;
    bool sol;
    for(int i = 2; i <= MAX; i++){
        if(bs.test(i)){
            p = i;
            dig = 0;
            m = 1;
            while(p > 0){
                dig++;
                m *= 10;
                p /= 10;
            }
            m /= 10;
            p = i;
            sol = true;
            for(int j = 1; j < dig; j++){
                p = p/10 + (p%10)*m;
                //cout << "test: " << p  << " i: " << i << endl;
                if(!bs.test(p)){
                    sol = false;
                    break;
                }
            }
            if(sol){
                cout << i << endl;
                num++;
            }
        }
    }
    cout << num << endl;

    return 0;
}
