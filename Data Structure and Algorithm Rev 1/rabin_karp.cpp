// My Rabin-Karp string matching algorithm implementation
// Solve Kattis problem: https://open.kattis.com/problems/stringmatching

#include <iostream>
#include <vector>

using namespace std;

// constexpr int base = 131 // ascii have 127 only
// constexpr int prime = 1000000007
// constexpr int prime = 1000000009
// constexpr int prime = 1000999777
// other prime https://codeforces.com/blog/entry/19410

class RabinKarpStringMatcher {
    long long base, mod;
    vector<int> hash, basePow;

    int computeHash(string s) {
        if(s.size() == 0)
            return 0;

        long long h = s[0];
        for(int i = 1; i < s.size(); i++) {
            h = (h * base + s[i]) % mod;
        }

        return h;
    }

    int computeHash(int idx, int len) {
        if(idx + len > hash.size()) {
            return -1;
        }

        if(idx == 0) {
            return hash[len - 1];
        }

        return (hash[idx + len - 1] - (1LL * hash[idx - 1] * basePow[len]) % mod + mod) % mod;
    }

public:
    // base, mod must in int range, mod must be prime
    RabinKarpStringMatcher(string s, long long base, long long mod) : base(base), mod(mod) {
        // compute prefix hash
        hash.resize(s.size());
        hash[0] = s[0] % mod;
        for(int i = 1; i < s.size(); i++) {
            hash[i] = (hash[i-1] * base + s[i]) % mod;
        }

        // compute basePow
        basePow.resize(s.size());
        basePow[0] = 1;
        for(int i = 1; i < s.size(); i++) {
            basePow[i] = (basePow[i-1] * base) % mod;
        }
    }

    bool IsMatch(string pattern, int idx) {
        return computeHash(pattern) == computeHash(idx, pattern.size());
    }

    vector<int> FindAllMatches(string pattern) {
        if(pattern == "") {
            return {};
        }

        int patternHash = computeHash(pattern);
        vector<int> ans;
        for(int i = 0; i + pattern.size() <= hash.size(); i++) {
            if(patternHash == computeHash(i, pattern.size())) {
                ans.push_back(i);
            }
        }

        return ans;
    }

};

int main() {
    string s, p;
    while(getline(cin, p) && getline(cin, s)) {
        RabinKarpStringMatcher matcher(s, 131, 1000000007);
        auto matches = matcher.FindAllMatches(p);
        for(int i = 0; i < matches.size(); i++) {
            cout << matches[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
