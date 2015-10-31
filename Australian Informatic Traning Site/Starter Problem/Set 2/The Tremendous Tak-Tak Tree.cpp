#include <iostream>
#include <fstream>

using namespace std;

ifstream in("taktakin.txt");
ofstream out("taktakout.txt");

int main()
{
    int fruit, days = 0;
    in >> fruit;
    while(fruit%11 != 1){
        fruit *= 2;
        days++;
    }
    out << days << " " << fruit << endl;
    return 0;
}
