#include <iostream>
#include <fstream>

using namespace std;

ifstream in("mixin.txt");
ofstream out("mixout.txt");

int main()
{
    int up, down;
    in >> up >> down;
    if(up%down == 0){out << up/down << endl;}
    else{out << up/down << " " << up%down << "/" << down << endl;}
    return 0;
}
