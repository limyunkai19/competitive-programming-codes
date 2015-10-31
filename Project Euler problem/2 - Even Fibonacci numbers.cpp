#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long sum = 0, pre = 1, temp, now=2;
    while(now < 4000000){
        if(now%2 == 0){
            sum += now;
        }
        temp = now;
        now = pre + now;
        pre = temp;
    }
    cout << sum << endl;
    return 0;
}
