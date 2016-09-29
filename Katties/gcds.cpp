// observation:
// 1) gcd(a, b) | b, thus gcds(lo, hi) is capped as gcd(lo+1, hi)
// 2) gcd(a, b) | a, divisor of a

#include <iostream>
#include <queue>
#include <set>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int a[100100];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    set<int> unique;
    queue<int> last_gcd;
    unique.insert(a[n-1]);
    last_gcd.push(a[n-1]);

    for(int i = n-2; i >= 0; i--){
        queue<int> cur_gcd;
        cur_gcd.push(a[i]);
        unique.insert(a[i]);
        int pre = a[i];

        while(!last_gcd.empty()){
            int cur = last_gcd.front(); last_gcd.pop();
            int g = gcd(cur, pre);

            if(g != pre){
                cur_gcd.push(g);
                pre = g;
                unique.insert(g);
            }
        }

        last_gcd = cur_gcd;
    }

    cout << unique.size() << endl;

    return 0;
}