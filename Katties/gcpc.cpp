// https://open.kattis.com/problems/gcpc
// Time on Kattis: 0.40 sec

#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;
typedef pair<ii, int> score;

template<class Type>
using ordered_set = tree<Type, null_type, less<Type>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<score> teams(n+1);
    ordered_set<score> ranking;
    for(int i = 1; i <= n; i++) {
        teams[i] = score(ii(0, 0), i);
        ranking.insert(teams[i]);
    }

    while(m--) {
        int t, p;
        cin >> t >> p;

        ranking.erase(teams[t]);
        teams[t].first.first--;
        teams[t].first.second += p;
        ranking.insert(teams[t]);

        cout << ranking.order_of_key(teams[1])+1 << '\n';
    }

    return 0;
}
