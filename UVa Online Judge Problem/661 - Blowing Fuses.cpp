#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n, m, c, max_power, power, a, tc = 0;
    int amp[23];
    bool used[23];
    scanf("%d %d %d", &n, &m, &c);
    while(n != 0){
        tc++;
        memset(used, false, sizeof used);
        max_power = 0;
        power = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &amp[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &a);
            if(used[a]){
                power -= amp[a];
                used[a] = false;
            }
            else{
                power += amp[a];
                if(power > max_power){
                    max_power = power;
                }
                used[a] = true;
            }
        }
        if(power <= c){
            printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n", tc, max_power);
        }else{
            printf("Sequence %d\nFuse was blown.\n\n", tc);
        }

        scanf("%d %d %d", &n, &m, &c);
    }

    return 0;
}
