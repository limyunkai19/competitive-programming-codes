#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<int> rod;

void solve(int i, int s1, int s2) {
    if(s1 == s2) {
        ans = max(ans, s1);
    }
    if(i == rod.size()) {
        return;
    }

    solve(i+1, s1+rod[i], s2);
    solve(i+1, s1, s2+rod[i]);
    solve(i+1, s1, s2);
}
int main() {
    int n;
    cin >> n;
    rod.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> rod[i];
    }

    solve(0, 0, 0);

    cout << ans << endl;

    return 0;
}
