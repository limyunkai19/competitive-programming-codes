#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

#define MAX 1000000

using namespace std;

typedef pair<int, int> ii;

vector<int> prime;
bitset<1000010> bs;

void sieve(){
    bs.reset();
    bs.flip();

    bs[0] = bs[1] = false;
    for(long long i = 2; i <= MAX; i++){
        if(bs[i]){
            prime.push_back(i);
            for(long long j = i*i; j <= MAX; j += i)
                bs[j] = false;
        }
    }
}

vector<ii> prime_factorize(int n){
    vector<ii> ans;
    for(int i = 0; prime[i] <= sqrt(n)+1; i++){
        if(n%prime[i] == 0){
            int num = 0;
            while(n%prime[i] == 0){
                n /= prime[i];
                num++;
            }
            ans.push_back(ii(prime[i], num));
        }
    }
    if(n != 1)
        ans.push_back(ii(n, 1));
    return ans;
}

int factorial_factor(int x, int factor){
    int ans = 0;
    while(x > 0){
        x /= factor;
        ans += x;
    }
    return ans;
}


int main() {
    sieve();
    int n, m;
    while(cin >> m >> n){
        vector<ii> n_prime;
        n_prime = prime_factorize(n);

        bool divides = true;
        if(n == 0)
            divides = false;
        for(int i = 0; i < n_prime.size() && divides; i++){
            int p = n_prime[i].first, num = n_prime[i].second;
            if(factorial_factor(m, p) < num)
                divides = false;

        }
        cout << n;
        if(divides)
            cout << " divides ";
        else
            cout << " does not divide ";
        cout << m << "!\n";
    }


    return 0;
}