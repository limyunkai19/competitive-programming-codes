#include <iostream>

using namespace std;

int modP(int base, int power, int mod){
    if(power == 0){
        return 1;
    }
    else{
        if(power%2 == 0){
            int temp = modP(base, (power/2), mod);
            temp = temp*temp;
            temp %= mod;
            return temp;
        }
        else{
            int temp = modP(base, (power-1), mod);
            temp *= (base%mod);
            temp %= mod;
            return temp;
        }
    }
}

int main()
{
    int base, power, mod, ans = 1;
    while(cin >> base >> power >> mod){
        base %= mod;
        cout << modP(base, power, mod) << "\n";
    }
    return 0;
}
