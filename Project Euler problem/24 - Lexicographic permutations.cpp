#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int permutate[10];

int main()
{
    int n = 1000000;
    for(int i = 0; i < 10; i++){
        permutate[i] = i;
    }
    for(int i = 1; i < n; i++){
        next_permutation(permutate, permutate+10);
    }
    for(int i = 0; i < 10; i++){
        cout << permutate[i];
    }
    cout << endl;
    return 0;
}
