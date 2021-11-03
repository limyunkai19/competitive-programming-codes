// My implementatio of sliding window algorithm
// Solve Leetcode problem: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

#include <string>
#include <vector>

using namespace std;

// useful for finding min window
// expand right to largest possible then contract l one at a time
namespace RightValidLeftOnce {
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int numChar = 0;
        vector<int> fre(130, 0);

        int r = 0, ans = 0;
        for(int l = 0; r < s.size(); l++) {
            // expand window
            for(; r < s.size(); r++) {
                // check if can include r
                if(numChar == k && fre[s[r]] == 0) {
                    // cannot include
                    break;
                }

                fre[s[r]]++;
                if(fre[s[r]] == 1) {
                    numChar++;
                }
            }

            // record
            ans = max(ans, r-l);

            // contract window
            fre[s[l]]--;
            if(fre[s[l]] == 0) {
                numChar--;
            }
        }

        return ans;
    }
}

// useful for finding max window
// expand right one at a time then contract l until valid
namespace RightOnceLeftValid {
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int numChar = 0;
        vector<int> fre(130, 0);

        int l = 0, ans = 0;
        for(int r = 0; r < s.size(); r++) {
            // include r
            fre[s[r]]++;
            if(fre[s[r]] == 1) {
                numChar++;
            }

            // ensure window is valid
            for(; numChar > k; l++) {
                fre[s[l]]--;
                if(fre[s[l]] == 0) {
                    numChar--;
                }
            }

            // record
            ans = max(ans, r-l+1);
        }

        return ans;
    }
}
