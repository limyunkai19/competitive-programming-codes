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
    int n, block[60], sum, moves, tc = 1;
    cin >> n;
    while(n != 0){
        sum = 0; moves = 0;
        for(int i = 0; i < n; i++){
            cin >> block[i];
            sum += block[i];
        }
        sum /= n;
        for(int i = 0; i < n; i++){
            if(block[i] > sum){
                moves += block[i] - sum;
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", tc++, moves);
        cin >> n;
    }

    return 0;
}
