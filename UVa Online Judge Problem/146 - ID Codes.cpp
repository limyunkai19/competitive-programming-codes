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
    string a;
    cin >> a;
    while(a != "#"){
        if(next_permutation(a.begin(), a.end())){
            printf("%s\n", a.c_str());
        }
        else{
            cout << "No Successor" << endl;
        }
        cin >> a;
    }

    return 0;
}
