#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

unsigned long long int translate(string x)
{
    unsigned long long int num=1;
    for(int i=0; i < x.length(); i++)
    {
        num *= alpha.find(x.at(i))+1;
    }
    return num;
}

int main()
{
    string comet, group;
    ofstream output ("ride_out.txt");
    ifstream input ("ride_in.txt");
    input >> comet >> group;
    if(translate(comet)%47 == translate(group)%47)
    {   output << "GO" << endl;   }
    else
    {   output << "STAY" << endl; }
    return 0;
}
