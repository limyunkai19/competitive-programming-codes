#include <iostream>

#define mod 1000000009

using namespace std;

int main(){
    string bit;
    cin >> bit;

    long long zero = 0, move = 0, stay = 1, new_move, new_stay;

    for(int i = bit.size()-1; i >= 0; i--){
        if(bit[i] == '0'){
            zero++;
        }
        if(bit[i] == '1'){
            new_stay = move + stay;
            new_move = zero*stay + (zero+1)*move;

            zero = 0;
            move = new_move % mod;
            stay = new_stay % mod;
        }
    }

    cout << (move+stay)%mod << endl;
}