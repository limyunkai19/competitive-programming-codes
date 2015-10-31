#include <iostream>
#include <fstream>

using namespace std;

ifstream in("countin.txt");
ofstream out("countout.txt");

int main()
{
    int n;
    in >> n;
    for(int i = 1; i <= n; i++)
    out << i << endl;
    return 0;
}
