#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int oddsum[105];

int main()
{
    oddsum[0] = 0;
    for(int i = 1; i < 105; i++){
        if(i%2 == 1){
            oddsum[i] = oddsum[i-1] + i;
        }
        else{
            oddsum[i] = oddsum[i-1];
        }
    }
    int n, a, b, tc = 1;
    cin >> n;
    while(n--){
        cin >> a >> b;
        printf("Case %d: %d\n", tc++, oddsum[max(a, b)] - oddsum[min(a, b) - 1]);
    }


    return 0;
}
