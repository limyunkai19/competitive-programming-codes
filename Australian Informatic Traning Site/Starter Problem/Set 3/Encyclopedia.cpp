#include <iostream>
#include <fstream>

using namespace std;

ifstream in("encyin.txt");
ofstream out("encyout.txt");

int main()
{
    int n, q;
    in >> n >> q;
    int word[n], page;
    for(int i = 0; i < n; i++){in >> word[i];}
    for(int i = 0; i < q; i++){
        in >> page;
        out << word[page-1] << endl;;
    }
    return 0;
}
