#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long int abc = 0;
    for(int a = 1; a <= 500; a++){
        for(int b = a; b <= 500; b++){
            double c = sqrt(a*a + b*b);
            if(a + b + c == 1000)
            {
                abc = a*b*c;
                break;
            }
        }
        if(abc > 0){
            break;
        }
    }
    cout << abc << endl;
    return 0;
}
