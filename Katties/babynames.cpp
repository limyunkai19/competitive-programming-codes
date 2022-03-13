// https://open.kattis.com/problems/babynames
// Time on Kattis: 0.52 sec

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
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ordered_set<string> gender1, gender2;

    int type;
    while(cin >> type) {
        if(type == 0) break;

        if(type == 1) {
            // add suggestion
            string s;
            int gender;
            cin >> s >> gender;

            if(gender != 1) {
                gender2.insert(s);
            }
            if(gender != 2) {
                gender1.insert(s);
            }
        }

        if(type == 2) {
            // remove suggestion
            string s;
            cin >> s;

            gender1.erase(s);
            gender2.erase(s);
        }

        if(type == 3) {
            // query prefix
            string s1, s2;
            int gender;
            cin >> s1 >> s2 >> gender;

            int ans = 0;
            if(gender != 1) {
                ans += gender2.order_of_key(s2) - gender2.order_of_key(s1);
            }
            if(gender != 2) {
                ans += gender1.order_of_key(s2) - gender1.order_of_key(s1);
            }

            cout << ans << '\n';
        }
    }

    return 0;
}
