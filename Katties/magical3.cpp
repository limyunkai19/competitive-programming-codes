#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int solve(int n){
    if(n == 3) return 4;
    if(n < 7) return 0;

    n -= 3;
    for(int i = 4; i <= sqrt(n)+1; i++){
        if(n%i == 0) return i;
    }
    if(n % 3 == 0 && n/3 >= 4)
        return n/3;
    if(n % 2 == 0 && n/2 >= 4)
        return n/2;

    return n;
}

int main(){
    int n;
    while(cin >> n && n != 0){
        int ans = solve(n);
        if(!ans)
            cout << "No such base" << endl;
        else
            cout << ans << endl;
    }

}