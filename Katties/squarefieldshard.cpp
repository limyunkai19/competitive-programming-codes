#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

vector<ii> points;
int mask, dp[1<<15];

bool can_cover(int x, int y, int l, int i){
    if(points[i].first < x || points[i].first > x+l)
        return false;
    if(points[i].second < y || points[i].second > y+l)
        return false;
    return true;
}

int min_square_cover(int n, int state, int l){
    if(dp[state] != -1)
        return dp[state];

    int ans = 20, s = 0;
    while( !(1<<s & state) ) s++;

    for(int i = s; i < n; i++){
        if(1<<i & state){
            // try cover s and i (s might = i => mean cover 1 point)
            int next_state = state;
            int x = points[s].first, y = min(points[s].second, points[i].second);
            if(points[i].first > x+l)
                // too far impossible
                break;
            if(!can_cover(x, y, l, s) || !can_cover(x, y, l, i))
                continue;

            for(int j = s; j < n; j++){
                if( (1<<j & state) && can_cover(x, y, l, j)){
                    next_state &= mask&~(1<<j);
                }
            }

            ans = min(ans, min_square_cover(n, next_state, l)+1);
        }
    }

    return dp[state] = ans;
}

int main(){
    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++){
        int n, k;
        cin >> n >> k;

        points.clear();
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            points.push_back(ii(x, y));
        }

        // sorting reduce complexity per state reduce from O(n^2) to O(n)
        // using the observation that the left most point must cover,
        // greedily make the square as right as possible
        sort(points.begin(), points.end());

        mask = (1<<n)-1;

        // binary search the length of square
        int hi = 65000, lo = 0, mid, ans;

        while(hi >= lo){
            mid = (hi+lo)/2;

            // set up and base case, 0 sqaure to cover 0 point
            memset(dp, -1, sizeof dp); dp[0] = 0;

            if(min_square_cover(n, mask, mid) <= k){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }


    return 0;
}