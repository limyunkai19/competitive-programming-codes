#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long fac[21];
    fac[0] = 1;
    for(int i = 1; i < 21; i++){
        fac[i] = i*fac[i-1];
    }
    map<char, int> alpha;
    int n;
    cin >> n;
    string word;
    long long int ways;
    for(int i = 1; i <= n; i++){
        alpha.clear();
        cin >> word;
        ways = fac[word.size()];
        for(int j = 0; j < word.size(); j++){
            alpha[word.at(j)]++;
        }
        for(map<char, int>::iterator it = alpha.begin(); it != alpha.end(); it++){
            ways /= fac[it->second];
        }
        cout << "Data set " << i << ": " << ways << endl;
    }

    return 0;
}
