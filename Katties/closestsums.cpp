#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int a[1500];

int main(){
    int n, m, x, tc = 0;
    while(cin >> n){
        tc++;
        set<int> s;
        s.insert(1000000000);
        s.insert(-1000000000);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int j = 0; j < i; j++){
                s.insert(a[i]+a[j]);
            }
        }
        cin >> m;
        cout << "Case " << tc << ":" << endl;
        while(m--){
            cin >> x;
            set<int>::iterator it = s.upper_bound(x);
            int a = *it;
            it--;
            int b = *it;
            if(abs(a-x) > abs(b-x)){
                cout << "Closest sum to " << x << " is " << b << '.' << endl;
            }
            else{
                cout << "Closest sum to " << x << " is " << a << '.' << endl;
            }

        }
    }

    return 0;
}