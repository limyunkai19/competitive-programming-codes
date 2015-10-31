#include <iostream>

using namespace std;

int main()
{
    int a, d;
    unsigned int b, c;
    while(cin >> a){
        b = a;
        c = 0;
        c += b%(1<<8);
        c=c<<8; b=b>>8;
        c += b%(1<<8);
        c=c<<8; b=b>>8;
        c += b%(1<<8);
        c=c<<8; b=b>>8;
        c += b%(1<<8);
        d = c;
        cout << a << " converts to " << d <<  endl;
    }

    return 0;
}
