#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

long long sum[111][111];

int main()
{
    memset(sum, 0, sizeof sum);
    ifstream triangle("triangle.txt");
    int n = 100;
    long long max_sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
        }
        for(int j = 1; j <= i; j++){
            triangle >> sum[i][j];
            sum[i][j] += max(sum[i-1][j], sum[i-1][j-1]);
        }
    }
    for(int i = 1; i <= n; i++){
        max_sum = max(max_sum, sum[n][i]);
    }
    cout << max_sum << endl;

    return 0;
}
