// link: https://csacademy.com/ieeextreme-practice/task/xtreme-teams/

#include <iostream>
#include <vector>
using namespace std;

string toBin(int n, int m) {
    string bin;
    for(int i = 0; i < m; i++, n /= 2) {
        bin += '0' + n % 2;
    }
    return bin;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        int mask = (1<<m) - 1;
        vector<int> val(n, 0);
        for(int i = 0; i < n; i++) {
            char c;
            for(int j = 0; j < m; j++) {
                cin >> c;
                val[i] *= 2;
                if(c == 'y') {
                    ++val[i];
                }
            }
        }

        long long ans = 0;
        int upperBit = min(m, 15);
        int lowerBit = m - upperBit;
        int lowerMask = (1<<lowerBit) - 1;
        vector<vector<int>> setCount(1<<lowerBit, vector<int>(1<<upperBit, 0));
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int v = val[i] | val[j];
                if(v == mask) {
                    ans += i;
                    continue;
                }

                int required = ~v & mask;
                int upperReq = required >> lowerBit;
                int lowerReq = required & lowerMask;
                int invLowerReq = ~required & lowerMask;
                for(int s = invLowerReq; ; s = (s-1)&invLowerReq) {
                    ans += setCount[lowerReq | s][upperReq];
                    if(s == 0) break;
                }
            }

            // add val[i] to the set
            int upperVal = val[i] >> lowerBit;
            int lowerVal = val[i] & lowerMask;
            for(int s = upperVal; ; s = (s-1)&upperVal) {
                setCount[lowerVal][s]++;
                if(s == 0) break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
