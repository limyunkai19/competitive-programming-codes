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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long a, b, carry, count;
    cin >> a >> b;
    while(!(a == 0 && b == 0)){
        carry = 0;
        count = 0;
        while(a > 0 || b > 0){
            carry = (a%10 + b%10 + carry)/10;
            if(carry > 0){
                count++;
            }
            a/= 10; b/= 10;
        }
        /*if(carry > 0){
            count++;
        }*/
        if(count == 0){
            printf("No carry operation.\n");
        }
        else if(count == 1){
            printf("1 carry operation.\n");
        }
        else{
            printf("%ld carry operations.\n", count);
        }

        cin >> a >> b;
    }

    return 0;
}
