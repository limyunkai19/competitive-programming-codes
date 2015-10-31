#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double limit, climb, factor, drop, position = 0, day = 0;
    cin >> limit >> climb >> drop >> factor;

    while(limit != 0){
        factor *= (climb/100);
        position = 0; day = 0;

        while(position <= limit && position >= 0){

            day++;
            if(climb > 0){

                position += climb;
                climb -= factor;
                if(position > limit){
                    printf("success on day %g\n", day);
                    break;
                }
                else{
                    position -= drop;
                }
            }
            else{
                position -= drop;
            }
        }
        if(position < 0){
            printf("failure on day %g\n", day);
        }
        cin >> limit >> climb >> drop >> factor;
    }
    return 0;
}
