#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool is_palindrome_base2(int n){
    if(n%2 == 2){
        return false;
    }
    vector<int> binary;
    while(n > 0){
        binary.push_back(n%2);
        n /= 2;
    }
    int sz = binary.size();
    for(int i = 0; i <= sz/2; i++){
        if(binary[i] != binary[sz-1-i]){
            return false;
        }
    }
    return true;
}

int main()
{
    int palindrome, sum = 0;
    for(int a = 0; a < 10; a++){
        for(int b = 0; b < 10; b++){
            for(int c = 0; c < 10; c++){
                palindrome = 100000*a + 10000*b + 1000*c + 100*c + 10*b + a;    //even length;
                if(palindrome == 0){
                    continue;
                }
                while(palindrome%10 == 0){
                    palindrome /= 10;
                }
                if(is_palindrome_base2(palindrome)){
                    sum += palindrome;
                }
                palindrome = 10000*a + 1000*b + 100*c + 10*b + a;               //odd length
                while(palindrome%10 == 0){
                    palindrome /= 10;
                }
                if(is_palindrome_base2(palindrome)){
                    sum += palindrome;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
