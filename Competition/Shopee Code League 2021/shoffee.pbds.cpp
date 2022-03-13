#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;

template<class Type>
using ordered_set = tree<Type, null_type, less<Type>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n, k;
    cin >> n >> k;

    int pre = 0;
    vector<int> a(n), sum(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
        sum[i] = pre + a[i];
        pre = sum[i];
    }

    ordered_set<ii> s;
    for(int i = 0; i < n; i++) {
        s.insert(ii(sum[i], i));
    }

    int ans = 0;
    pre = 0;
    for(int i = 0; i < n; i++) {
        ans += s.size() - s.order_of_key(ii(pre, -1));
        s.erase(ii(sum[i], i));
        pre = sum[i];
    }

    cout << ans << endl;

    return 0;
}
