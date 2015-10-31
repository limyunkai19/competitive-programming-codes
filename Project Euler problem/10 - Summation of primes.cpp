#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primelist;

int main()
{
    primelist.push_back(2);
    unsigned long long int n = 2000000, k=3, odd=3, sum = 2;
    bool prime=true;
    while(k < n){
        prime = true;
        for(int i=0; primelist[i] <= sqrt(k); i++){
            if(k%primelist[i] == 0){
                prime = false;
                break;
            }
        }
        if(prime == true){
            sum += k;
            primelist.push_back(k);
        }
        k += 2;
    }
    cout << sum << endl;

    return 0;
}
