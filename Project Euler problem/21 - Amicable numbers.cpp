#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool ami[20010];

int sum_div(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n%i == 0){
            sum += i;
        }
    }
    return sum;
}

int main()
{
    memset(ami, false, sizeof ami);
    int d, sum = 0;
    for(int i = 2; i < 10000; i++){
        if(!ami[i]){
            d = sum_div(i);
            if(sum_div(d) == i && d != i){
                ami[i] = true;
                ami[d] = true;
                if(d < 10000){
                    sum += d;
                }
                sum += i;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
