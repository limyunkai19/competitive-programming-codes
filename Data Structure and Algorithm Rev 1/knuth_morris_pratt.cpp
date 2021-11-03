// My Knuth–Morris–Pratt string matching algorithm implementation
// Solve Kattis problem: https://open.kattis.com/problems/stringmatching

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KMPStringMatcher {
    string pattern;
    vector<int> table;

public:
    KMPStringMatcher(string pattern) : pattern(pattern) {
        // build reset table
        table.assign(pattern.size()+1, -1);
        for(int i = 0, matchPos = -1; i < pattern.size(); ) {
            while(matchPos >= 0 && pattern[i] != pattern[matchPos]) {
                matchPos = table[matchPos];
            }

            table[++i] = ++matchPos;
        }
    }

    vector<int> FindAllMatches(string text) {
        vector<int> ans;
        for(int i = 0, matchPos = 0; i < text.size(); ) {
            while(matchPos >= 0 && text[i] != pattern[matchPos]) {
                matchPos = table[matchPos];
            }

            i++; matchPos++;
            if(matchPos == pattern.size()) {
                ans.push_back(i-matchPos);
                matchPos = table[matchPos];
            }
        }

        return ans;
    }
};

int main() {
    string s, p;
    while(getline(cin, p) && getline(cin, s)) {
        KMPStringMatcher matcher(p);
        auto matches = matcher.FindAllMatches(s);
        for(int i = 0; i < matches.size(); i++) {
            cout << matches[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
