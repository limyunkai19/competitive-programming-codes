#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

bitset<1100000> self;

int next_self(int n){
    int a = n;
    while(n > 0){
        a += n%10;
        n/=10;
    }
    return a;
}

void generate_self(){
    int a;
    for(int i = 1; i <= 1000000; i++){
        if(self.test(i)){
            a = next_self(i);
            while(a <= 1000000){
                if(!self.test(a)){break;}
                self.set(a, false);
                a = next_self(a);
            }
        }
    }
}

int main()
{
    self.reset(); self.flip();
    generate_self();
    for(int i = 1; i <= 1000000; i++){
        if(self.test(i)){
            printf("%d\n", i);
        }
    }

    return 0;
}
