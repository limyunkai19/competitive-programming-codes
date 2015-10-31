#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    long long a, b;
    while(cin >> a >> b && b != 0){
        cout << a/b << ' ' << a%b << " / " << b << endl;
    }

    return 0;
}