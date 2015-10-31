#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream output ("addout.txt");
    ifstream input ("addin.txt");
    int a, b;
    input >> a >> b;
    output << a + b << endl;
    return 0;
}
