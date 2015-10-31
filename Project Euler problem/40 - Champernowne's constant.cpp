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
    vector<int> digit;
    int pos = 1, mul = 1, ans = 1, tem, fac, dig;
    for(int i = 1;; i++){
        digit.clear();
        tem = i;
        while(tem > 0){
            digit.push_back(tem%10);
            tem /= 10;
        }
        for(int k = digit.size() - 1; k >= 0; k--, pos++){
            if(pos == mul){
                ans *= digit[k];
                mul *= 10;
                cout << digit[k] << endl;
            }
        }
        if(pos > 1000000){
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
