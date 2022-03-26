#include <iostream>
#include <vector>

using namespace std;

// return true if p is prefix of s[i:]
// can use rolling hash to optimize this function
inline bool match(int i, const string& s, const string& p) {
    int j;
    for(j = 0; j < p.size() && i < s.size(); i++, j++) {
        if(s[i] != p[j]) {
            return false;
        }
    }

    return j == p.size();
}

void backtracking(int idx, vector<int>& candidate, vector<int>& ans, vector<bool>& taken, const string& s, const vector<string>& pieces) {
    if(idx == s.size()) {
        if(candidate.size() < ans.size()) {
            ans = candidate;
        }
        return;
    }

    // prune
    if(candidate.size() >= ans.size()) {
        return;
    }

    // pick matching string for idx, can use rolling hash to optimize
    for(int i = 0; i < pieces.size(); i++) {
        if(taken[i]) continue;

        if(match(idx, s, pieces[i])) {
            // match, try this
            taken[i] = true;
            candidate.push_back(i);
            backtracking(idx + pieces[i].size(), candidate, ans, taken, s, pieces);
            taken[i] = false;
            candidate.pop_back();
        }
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    cin >> n;
    vector<string> pieces(n);
    vector<bool> taken(n, false);
    vector<int> ans(n+1), candidate;

    for(int i = 0; i < n; i++) {
        cin >> pieces[i];
    }

    backtracking(0, candidate, ans, taken, s, pieces);

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i]+1 << ' ';
    }

    return 0;
}
