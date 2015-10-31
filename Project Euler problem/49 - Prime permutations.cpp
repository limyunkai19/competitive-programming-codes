#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime_list;
vector<int> prime_4_digit;
bool isprime[200000];

bool digit_same(int a, int b, int c){
    int used[10], usedc[10];
    memset(used, 0, sizeof used);
    memset(usedc, 0, sizeof usedc);
    while(a > 0){
        used[a%10]++;
        usedc[a%10]++;
        a /= 10;
    }
    while(b > 0){
        used[b%10]--;
        if(used[b%10] < 0){
            return false;
        }
        b /= 10;
    }
    while(c > 0){
        usedc[c%10]--;
        if(usedc[c%10] < 0){
            return false;
        }
        c /= 10;
    }
    return true;
}

int main()
{
    memset(isprime, false, sizeof isprime);
    prime_list.push_back(2);
    isprime[2] = true;
    bool prime;
    for(int i = 3; i < 10000; i+=2){
        prime = true;
        for(int j = 0; prime_list[j] <= sqrt(i); j++){
            if(i%prime_list[j] == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            prime_list.push_back(i);
            if(i > 1000){
                prime_4_digit.push_back(i);
            }
            isprime[i] = true;
        }
    }
    for(int i = 0; i < prime_4_digit.size(); i++){
        if(prime_4_digit[i] == 1487){
            continue;
        }
        for(int j = i+1; j < prime_4_digit.size(); j++){
            if(isprime[2*prime_4_digit[j]-prime_4_digit[i]] && 2*prime_4_digit[j]-prime_4_digit[i] < 10000){
                if(digit_same(prime_4_digit[i], prime_4_digit[j], 2*prime_4_digit[j]-prime_4_digit[i])){
                    cout << prime_4_digit[i] << prime_4_digit[j] << 2*prime_4_digit[j]-prime_4_digit[i] << endl;
                }
            }
        }
    }

    return 0;
}
