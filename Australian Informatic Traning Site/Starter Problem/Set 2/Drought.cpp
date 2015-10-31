#include <iostream>
#include <fstream>

using namespace std;

ifstream in("rainin.txt");
ofstream out("rainout.txt");

int main()
{
    int max, tank = 0, now, days;
    in >> days >> max;
    days = 0;
    while(tank < max){
        in >> now;
        tank += now;
        days++;
    }
    out << days << endl;
    return 0;
}
