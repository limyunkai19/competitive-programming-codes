#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<int> rod;

void solve(int i, int s1, int s2, int remaining) {
    // found answer
    if(s1 == s2) {
        ans = max(ans, s1);
    }
    // end
    if(i == rod.size()) {
        return;
    }
    // rod cannot be balanced
    if (abs(s1 - s2) > remaining) {
        return;
    }
    // will never find a greater answer
    if (s1 + s2 + remaining <= ans * 2) {
        return;
    }

    remaining -= rod[i];
    solve(i+1, s1+rod[i], s2, remaining);
    solve(i+1, s1, s2+rod[i], remaining);
    solve(i+1, s1, s2, remaining);
}
int main() {
    int n, sum = 0;
    cin >> n;
    rod.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> rod[i];
        sum += rod[i];
    }

    solve(0, 0, 0, sum);

    cout << ans << endl;

    return 0;
}
