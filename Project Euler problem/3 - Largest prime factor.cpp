#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long int k = 600851475143, ptemp = 3;
    while(k%2 == 0)
    {
        cout << ptemp << endl;
        k /= 2;
    }
    while(k != 1 && k >= ptemp)
    {
        if(k%ptemp == 0)
        {
            while(k%ptemp == 0)
            {
                k/=ptemp;
            }
        }
        ptemp += 2;
    }
    cout << ptemp -2 << endl;
    return 0;
}
