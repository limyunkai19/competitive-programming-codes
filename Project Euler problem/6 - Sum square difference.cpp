#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int sum_square = 0, sum = 0;
    for(int i = 1; i <= 100; i++){
        sum_square += i*i;
        sum += i;
    }
    cout << sum*sum - sum_square << endl;
    return 0;
}
