#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = atan2(1, 0)*2;
const int R = 6440;

int main()
{
    int distant;
    double angle, arc, chord;
    string unit;
    while(cin >> distant >> angle >> unit){
        if(unit == "min"){
            angle /= 60;
        }
        if(angle > 180){
            angle = 360 - angle;
        }
        angle /= 180;           //arc dis
        angle *= PI;
        arc = angle*(R + distant);
        chord = sqrt(2*(R + distant)*(R + distant) - 2*(R + distant)*(R + distant)*(cos(angle)));
        printf("%.6f %.6f\n", arc, chord);

    }
    return 0;
}
