#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int power[24], D, B;

int ball(int current, int depth, int balls){
    if((balls - 1) == (power[D-depth+1] - 2)){
        return current;
    }
    if(balls%2 == 1){
        return ball((2*(current-power[depth-1])+power[depth]), depth+1, ceil(balls/2.0));
    }
    else{
        return ball((2*(current-power[depth-1])+power[depth]+1), depth+1, ceil(balls/2.0));
    }
}

int main()
{
    power[0] = 1;
    for(int i = 1; i <= 22; i++){
        power[i] = power[i-1]*2;
    }
    int tc;
    cin >> tc;
    while(tc--){
        cin >> D >> B;
        cout << ball(1, 1, B) << endl;
    }

    return 0;
}
