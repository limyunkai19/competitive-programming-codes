#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int ans = 0, base = 0;
    long long n;

    cin >> n;

    for(int i = 1; i <= sqrt(n)+1; i += 2){
        int p = i;
        if(i == 1) p++;

        int n_p = 0;
        while(n % p == 0){
            n /= p;
            n_p++;
        }
        if(n_p > ans){
            base = p;
            ans = n_p;
        }
    }

    // left with prime which will lead 1
    if(ans == 0)
        base = n;

    cout << base << endl;

    return 0;
}