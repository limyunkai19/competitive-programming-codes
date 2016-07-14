#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1);
const double equi = PI/3.0;

double angle(double c, double b, double a){
    // find angle BAC
    // law of cosine
    // a^2 = b^2 + c^2 - 2bc Cos(A)
    // cos(A) = (b^2 + c^2 - a^2) / 2bc

    double cosA = (b*b + c*c - a*a)/(2*b*c);
    if(cosA > 1 || cosA < -1) return -1000000;

    return acos(cosA);
}

bool check(double a, double b, double c, double side){
    if(abs(angle(side, a, b)+angle(side, a, c)-equi) > 1e-2)
        return false;
    if(abs(angle(side, b, c)+angle(side, b, a)-equi) > 1e-2)
        return false;
    if(abs(angle(side, c, a)+angle(side, c, b)-equi) > 1e-2)
        return false;
    return true;
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    // now a <= b <= c

    //                  |
    //                  /\
    //                 /  \
    //                     \

    double hi = a+b, lo = sqrt(c*c-a*a), side;

    while(hi - lo > 1e-6){
        side = (hi+lo)/2;
        double ang1 = angle(side, a, b);
        double ang2 = angle(side, a, c);

        // equi == 60 deg, need to search for 60 deg
        if(ang1 + ang2 == equi){
            break;
        }
        else if(ang1 + ang2 > equi){
            // need to be longer
            lo = side;
        }
        else{
            hi = side;
        }
    }

    // final check
    if(check(a, b, c, side)){
        // area = 1/2 ab sin C, sin 60 = sqrt(3)/2
        double area = 0.25 * side * side * sqrt(3.0);
        printf("%0.3f\n", area); // printf will roound off
    }
    else{
        printf("-1.000\n");
    }

    return 0;
}