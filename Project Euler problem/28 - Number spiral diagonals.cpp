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
    long long sum = 1;
    for(long long i = 3; i <= 1001; i+=2){
        sum += i*i + i*i - i + 1 + i*i - i + 1 - i + 1 + i*i - i + 1 - i + 1 - i + 1;

    }
    cout << sum << endl;
    return 0;
}
