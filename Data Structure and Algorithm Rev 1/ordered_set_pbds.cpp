// Ordered Set implementation with PBDS
// Solve Kattis problem: https://open.kattis.com/problems/continuousmedian
// Time on Kattis: 0.37 sec

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;

template<class Type>
using ordered_set = tree<Type, null_type, less<Type>, rb_tree_tag, tree_order_statistics_node_update>;

// usage
// ordered_set<int> s;
// s.insert(10);
// s.find_by_order(0); -> 10 (0-indexed)
// s.order_of_key(-10); -> 0
// s.order_of_key(10); -> 0
// s.order_of_key(11); -> 1
// ordered_set<ii> for multiset trick


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;
        ordered_set<ii> set;
        for(int i = 0; i < n; i++) {
            set.insert(ii(a[i], i));
            if(i % 2 == 0) {
                ans += set.find_by_order(i/2)->first;
            }
            else {
                ans += (set.find_by_order(i/2)->first + set.find_by_order(i/2+1)->first) / 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
