#include <iostream>
#include <fstream>

using namespace std;

ifstream in("listin.txt");
ofstream out("listout.txt");

int main()
{
    int a[1001] = {0}, num, n, max=0;
    in >> n;
    for(int i = 0; i < n; i++){
        in >> num;
        a[num]++;
        in >> num;
        a[num]++;
    }
    for(int i = 0; i < 1001; i++){
        if(a[i] > max){max = a[i];}
    }
    for(int i = 0; i < 1001; i++){
        if(a[i] == max){out << i << endl;}
    }
    return 0;
}
