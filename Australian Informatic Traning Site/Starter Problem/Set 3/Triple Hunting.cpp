#include <iostream>
#include <fstream>

using namespace std;

ifstream in("tripin.txt");
ofstream out("tripout.txt");

int main()
{
    int n, num;
    in >> n;
    int list[n], count=0;
    for(int i = 1; i <= n; i++){
        in >> num;
        if(num%3 ==0){list[count] = i; count++;}
    }
    if(count == 0){out << "Nothing here!" << endl;}
    else{
        out << count << endl;
        for(int i = 0; i < count; i++){out << list[i] << " ";}
        out << endl;
    }
    return 0;
}
