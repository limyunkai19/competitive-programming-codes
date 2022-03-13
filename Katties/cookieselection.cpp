// https://open.kattis.com/problems/cookieselection
// Time on Kattis: 0.66 sec
// Alternative directory contains solution with two heap

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;

template<class Type>
using ordered_set = tree<Type, null_type, less<Type>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int idx = 0;
    ordered_set<ii> cookies;

    string s;
    while(cin >> s) {
        if(s[0] == '#') {
            auto target = cookies.find_by_order(cookies.size()/2);
            cout << target->first << '\n';
            cookies.erase(target);
        }
        else {
            int c = stoi(s);
            cookies.insert(ii(c, ++idx));
        }
    }

    return 0;
}
