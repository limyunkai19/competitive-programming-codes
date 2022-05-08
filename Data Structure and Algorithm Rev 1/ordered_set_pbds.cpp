// Ordered Set implementation with PBDS
// Solve Kattis problem: https://open.kattis.com/problems/continuousmedian
// Time on Kattis: 0.33 sec

// Time and memory complexity will be based on n = number of item in the oredered set
// Time Complexity: O(log n) for insert, find_by_order, and order_of_key
// Memory Complexity: O(n)
// Usage:
//  - Initialize an ordered set, ordered_set<int> s
//  - Others standard c++'s set operations and time complexity applies
//  - For example, insert(x), size(), begin(), end(), find(x), erase(x)
//  - Get the i-th (0-based indexing) item from the set, s.find_by_order(i)
//  - Get the rank of an item in the set, s.order_of_key(x)
//  - Multiset trick, use ordered_set<pair<int, int>> s, to convert it to multiset
// Example:
//   ordered_set<int> s;
//   s.insert(10);
//   s.find_by_order(0); -> 10 (0-indexed)
//   s.order_of_key(-10); -> 0
//   s.order_of_key(10); -> 0
//   s.order_of_key(11); -> 1
//   ordered_set<ii> for multiset trick, s.insert(ii(x, uniqueID)), where ii is typedef for pair<int, int>

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;

template<class Type>
using ordered_set = tree<Type, null_type, less<Type>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;

        long long ans = 0;
        ordered_set<ii> set;
        for(int i = 0; i < n; i++) {
            cin >> x;
            set.insert(ii(x, i));
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
