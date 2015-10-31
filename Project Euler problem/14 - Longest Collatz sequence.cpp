#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long n = 1000000, temp, max_start, max=0;
    long long max_count = 0, count;
    for(int i = n; i >= 1; i--){
        temp = i;
        count = 1;
        while(temp != 1){
            if(temp%2 == 0){
                temp /= 2;
            }
            else{
                temp = 3*temp + 1;
            }
            if(temp > max){
                max = temp;
            }
            count++;
        }
        if(count > max_count){
            max_count = count;
            max_start = i;
        }
    }
    cout << max_start << endl;
    return 0;
}
