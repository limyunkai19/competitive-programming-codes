#include <iostream>
#include <fstream>

using namespace std;

ifstream in("dishin.txt");
ofstream out("dishout.txt");

int main()
{
    int n, now, sum, max, min;
    in >> n;
    in >> now;
    sum = now; max = now; min = now;
    for(int i = 1; i < n; i++){
        in >> now;
        sum += now;
        if(now > max){max = now;}
        if(now < min){min = now;}
    }
    sum /= n;
    out << min << " " << max << " " << sum<< endl;
    return 0;
}
