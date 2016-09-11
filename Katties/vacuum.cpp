#include <iostream>
#include <algorithm>

using namespace std;

int tubes[2005];

int main() {
    int L1, L2, n;
    cin >> L1 >> L2 >> n;

    for(int i = 0; i < n; i++){
        cin >> tubes[i];
    }
    sort(tubes, tubes+n);

    int ans = -1;
    for(int L1_idx = 0; L1_idx < n && tubes[L1_idx] <= (L1>>1); L1_idx++){
        for(int L2_idx = 0; L2_idx < n && tubes[L2_idx] <= (L2>>1); L2_idx++){
            if(L1_idx == L2_idx)
                continue;

            int L1_left = L1-tubes[L1_idx];
            int L2_left = L2-tubes[L2_idx];

            int L1_left_idx = upper_bound(tubes, tubes+n, L1_left)- tubes - 1;
            while(L1_left_idx == L1_idx || L1_left_idx == L2_idx)
                L1_left_idx--;

            int L2_left_idx = upper_bound(tubes, tubes+n, L2_left)- tubes - 1;
            while(L2_left_idx == L1_idx || L2_left_idx == L2_idx || L2_left_idx == L1_left_idx)
                L2_left_idx--;

            if(L1_left_idx < 0 || L2_left_idx < 0)
                continue;

            ans = max(ans, tubes[L1_idx]+tubes[L1_left_idx]+tubes[L2_idx]+tubes[L2_left_idx]);
        }
    }

    if(ans == -1)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}