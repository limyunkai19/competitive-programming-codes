#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int fifthpower[10];
    for(int i = 0; i < 10; i++){
        fifthpower[i] = i*i*i*i*i;
    }
    int num, sum=0;
    for(int a = 0; a < 10; a++){
        for(int b = 0; b < 10; b++){
            for(int c = 0; c < 10; c++){
                for(int d = 0; d < 10; d++){
                    for(int e = 0; e < 10; e++){
                        for(int f = 0; f < 10; f++){
                            num = 100000*a + 10000*b + 1000*c + 100*d + 10*e + f;
                            if(num == fifthpower[a] + fifthpower[b] + fifthpower[c] + fifthpower[d] + fifthpower[e] + fifthpower[f]){
                                sum += num;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sum-1 << endl;
    return 0;
}
