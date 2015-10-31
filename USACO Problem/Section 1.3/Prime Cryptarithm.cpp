#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool digit[10];

bool use_digit(int a){
    while(a > 0){
        if(!digit[a%10]){return false;}
        a /= 10;
    }
    return true;
}

int main()
{
    //freopen("crypt1.in", "r", stdin);
    //freopen("crypt1.out", "w", stdout);
    int n, dig, count = 0, final;
    memset(digit, false, sizeof digit);
    cin >> n;
    int set[n];
    for(int i = 0; i < n; i++){
        cin >> set[i];
        digit[set[i]] = true;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int unit = 0; unit < n; unit++){
                    dig = 100*set[i] + 10*set[j] + set[k];
                    if(dig*set[unit] < 1000 && use_digit(dig*set[unit])){
                        for(int ten = 0; ten < n; ten++){
                            if(dig*set[ten] < 1000 && use_digit(dig*set[ten])){
                                final = 10*dig*set[ten] + dig*set[unit];
                                if(final < 10000 && use_digit(final)){
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}
