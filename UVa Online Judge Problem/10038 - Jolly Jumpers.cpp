#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n, sequence[3010], diff;
    bool used[3010], isjolly;
    while(cin >> n){
        memset(used, false, sizeof used);
        isjolly = true;
        cin >> sequence[0];
        for(int i = 1; i < n; i++){
            cin >> sequence[i];
            diff = fabs(sequence[i] - sequence[i-1]);
            if(diff >= n || diff < 1){
                isjolly = false;
            }
            else{
                if(used[diff]){
                    isjolly = false;
                }
                used[diff] = true;
            }
        }
        if(isjolly){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }
    }
    return 0;
}
