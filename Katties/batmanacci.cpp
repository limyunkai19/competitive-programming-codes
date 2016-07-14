#include <iostream>
#include <cstdio>

using namespace std;

#define INF 1000000000000100000LL

long long fib[100100];

char find(int n, long long k){
    // S(n) = S(n-2) + S(n-1)

    if(n == 1) return 'N';
    if(n == 2) return 'A';

    if(fib[n-2] >= k)
        return find(n-2, k);
    else
        return find(n-1, k-fib[n-2]);

}


int main(){
    int n;
    long long k;

    cin >> n >> k;

    fib[1] = fib[2] = 1;
    for(int i = 3; i <= n+1; i++){
        fib[i] = fib[i-1]+fib[i-2];

        if(fib[i] > INF)
            fib[i] = INF;
    }

    cout << find(n, k) << endl;

    return 0;
}