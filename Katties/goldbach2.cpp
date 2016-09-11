#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bitset<33010> bs;
const int MAX = 33000;
vector<int> prime;

void sieve(){
    bs.reset();
    bs.flip();
    bs[0] = false;
    bs[1] = false;
    for(int i = 2; i < MAX; i++){
        if(bs.test(i)){
            prime.push_back(i);
            for(int j = i*i; j < MAX; j+=i){
                bs[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    int n, x;
    cin >> n;
    bool first = true;
    while(n--){
        if(!first) cout << endl;
        first = false;
        cin >> x;
        int idx = 0;
        vector<int> ans;
        while(prime[idx] <= x/2 && idx < prime.size()){
            if(bs[x-prime[idx]]){
                ans.push_back(prime[idx]);
            }
            idx++;
        }
        cout << x << " has " << ans.size() << " representation(s)" << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << '+' << x-ans[i] << endl;
        }
    }
    return 0;
}