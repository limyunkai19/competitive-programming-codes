#include <iostream>

using namespace std;

int main(){
    long long a, b, c;
    while(cin >> a >> b){
        c = a-b;
        if(c < 0)
            c = -c;
        cout << c << endl;
    }
    return 0;
}