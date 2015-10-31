#include <iostream>
#include <fstream>

using namespace std;

ifstream in("dictin.txt");
ofstream out("dictout.txt");

int main()
{
    int total, num, cur;
    bool found;
    in >> total >> num;
    int integer[total], whole[total];
    for(int i = 0; i < total; i++){in >> integer[i] >> whole[i];}
    for(int i = 0; i < num; i++){
        in >> cur;
        found = false;
        for(int j = 0; j < total; j++)
        {
            if(integer[j] == cur){out << whole[j] << endl; found = true; break;}
        }
        if(!found){out << "C?" << endl;}
    }

    return 0;
}
