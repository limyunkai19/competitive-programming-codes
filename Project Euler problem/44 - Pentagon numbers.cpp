#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

vector<int> penta;
bitset<100000000> ispen;

int main()
{
    int k = 2, minsol = 1e8, newpen;
    ispen.reset();
    ispen.set(1, true);
    ispen.set(5, true);
    penta.push_back(1);
    penta.push_back(5);
    while(penta[k-1] - penta[k-2] < minsol){
        k++;
        newpen = k*(3*k -1)/2;
        if(newpen > 1e8) break;
        for(int i = 0; i <= penta.size()/2; i++){
            if(ispen.test(newpen - penta[i])){
                if(ispen.test(abs(newpen - 2*penta[i]))){
                    if(abs(newpen - 2*penta[i]) < minsol){
                        minsol = abs(newpen - 2*penta[i]);
                    }
                }
            }
        }

        ispen.set(newpen, true);
        penta.push_back(newpen);
    }
    cout << minsol << endl;
    return 0;
}
