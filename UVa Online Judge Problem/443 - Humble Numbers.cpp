#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

vector<ll> humble;
map<ll, int> test;

void next_humble(ll a){
    if(a > 2000000000) return;
    else if(test[a] > 0) return;
    test[a]++;
    humble.push_back(a);
    next_humble(a*2);
    next_humble(a*3);
    next_humble(a*5);
    next_humble(a*7);
}

int main()
{
    next_humble(1);
    sort(humble.begin(), humble.end());
    int n;
    scanf("%d", &n);
    while(n != 0){
        if((n%100)/10 == 1){
            printf("The %dth humble number is %ld.\n", n, humble[n-1]);
        }
        else if(n%10 == 1){
            printf("The %dst humble number is %ld.\n", n, humble[n-1]);
        }
        else if(n%10 == 2){
            printf("The %dnd humble number is %ld.\n", n, humble[n-1]);
        }
        else if(n%10 == 3){
            printf("The %drd humble number is %ld.\n", n, humble[n-1]);
        }
        else{
            printf("The %dth humble number is %ld.\n", n, humble[n-1]);
        }


        scanf("%d", &n);
    }

    return 0;
}
