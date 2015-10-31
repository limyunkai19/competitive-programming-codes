#include <iostream>

using namespace std;

int main()
{
    unsigned long long int i, j, a, cycNow, cycMax, start, end;
    while(cin >> i >> j)
    {
        cycNow = 0;
        cycMax = 0;
        if(i > j)
        {
            start = j;
            end = i;
        }
        else
        {
            start = i;
            end = j;
        }
        for(unsigned long long int k = start; k <= end; k++)
        {
            cycNow = 1;
            a = k;
            while(a != 1)
            {
                if(a%2 == 0){a /= 2; cycNow++;}
                else{a = 3*a + 1; cycNow++;}
            }
            if(cycNow > cycMax){cycMax = cycNow;}
        }
        cout << i << " " << j << " " << cycMax << endl;

    }
    return 0;
}
