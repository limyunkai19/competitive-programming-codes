#include <iostream>
#include <fstream>

using namespace std;

ifstream in("bendin.txt");
ofstream out("bendout.txt");

int area(int x1, int y1, int x2, int y2)
{
    int area;
    area = (x2 - x1)*(y2 - y1);
    return area;
}

bool intersect(int x1, int x2, int y, /*coordinate of horinzontal segment*/
               int a, int b1, int b2 /*coordinates of vertical segment*/)
{
    if(b1 < y && b2 > y && x1 < a && x2 > a){return true;}
    else{return false;}
}

int main()
{
    int x1, y1, x2, y2, a1, b1, a2, b2;
    in >> x1 >> y1 >> x2 >> y2 >> a1 >> b1 >> a2 >> b2;
    int lInt, rInt, uInt, dInt;
    lInt = max(x1, a1);
    rInt = min(x2, a2);
    uInt = min(y2, b2);
    dInt = max(y1, b1);
    int areaInt;
    if(lInt < rInt && uInt > dInt){
        areaInt = area(lInt, dInt, rInt, uInt);
    }
    else{
        areaInt = 0;
    }
    out << area(x1, y1, x2, y2) + area(a1, b1, a2, b2) - areaInt << endl;
    return 0;
}
