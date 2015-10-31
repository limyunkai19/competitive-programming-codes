#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    freopen("cutein.txt", "r", stdin);
    freopen("cuteout.txt", "w", stdout);

    int cute = 0, dig;
    while(cin >> dig){
        if(dig == 0){
            cute++;
        }
        else{
            cute = 0;
        }
    }
    cout << cute << endl;
    return 0;
}
