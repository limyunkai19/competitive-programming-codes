#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primelist;

int main()
{
    primelist.push_back(2);
    int k = 3, n = 10001;
    bool prime;
    while(primelist.size() < n){
        prime = true;
        for(int i = 0; i < primelist.size() && primelist[i] <= sqrt(k); i++){
            if(k%primelist[i] == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            primelist.push_back(k);
        }

        k += 2;
    }
    cout << primelist[n-1] << endl;
    return 0;
}
