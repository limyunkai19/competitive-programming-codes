#include <iostream>
#include <vector>

using namespace std;

bool palindrome(unsigned long long int i)
{
    unsigned long long int k = i;
    bool palindrome = false;
    vector <int> digits;
    while(k != 0){
        digits.push_back(k%10);
        k /= 10;
    }
    for(int k = 0; k <= digits.size()/2; k++){
        if(digits[k] == digits[digits.size() - k - 1]){
            palindrome = true;
        }
        else{
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

int main()
{
    unsigned long long int temp, max = 0;
    for(int i = 999; i > 99; i--){
        for(int j = i; j > 99; j--){
            if(palindrome(j*i)){
                if(j*i > max){
                    max = j*i;
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}
