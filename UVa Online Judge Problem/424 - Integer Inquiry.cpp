#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    int ans[210], length=0, sz;
    memset(ans, 0, sizeof ans);
    string temp;
    while(cin >> temp){
        if(temp == "0"){
            break;
        }
        sz = temp.size();
        for(int i = sz-1, j = 0; i >= 0; i--, j++){
            ans[j] += int(temp.at(i) - '0');
        }
        length = max(length, sz);
    }
    int carry=0;
    for(int i = 0; i < length; i++){
        ans[i] += carry;
        carry = ans[i]/10;
        ans[i] %= 10;
    }
    while(carry > 0){
        ans[length] += carry%10;
        length++;
        carry /= 10;
    }
    for(int i = length-1; i >= 0; i--){
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
