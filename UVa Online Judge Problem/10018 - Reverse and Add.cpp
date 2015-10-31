#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

long long reverse(long long a){
    long long rev = 0;
    while(a > 0){
        rev*= 10;
        rev += a%10;
        a /= 10;
    }
    return rev;

}

int main()
{
    int n, count;
    cin >> n;
    long long a, rev;
    for(int i = 0; i < n; i++){
        count = 0;
        cin >> a;
        rev = reverse(a);
        while(rev != a){
            a += rev;
            count++;
            rev = reverse(a);
        }
        cout << count << " " << rev << endl;

    }

    return 0;
}
