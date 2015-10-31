#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("sitin.txt");
    ofstream out("sitout.txt");
    int row, seat, ppl;
    while(in >> row >> seat)
    {
        seat *= row;
        in >> ppl;
        if(ppl > seat){out << seat << " " << ppl - seat << endl;}
        else{out << ppl << " " << 0 << endl;}

    }
    return 0;
}
