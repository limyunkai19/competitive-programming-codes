#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    set<double> power;
    for(int i = 2; i <= 100; i++){
        for(int j = 2; j <= 100; j++){
            power.insert(pow(i, j));
        }
    }
    cout << power.size() << endl;
    return 0;
}
