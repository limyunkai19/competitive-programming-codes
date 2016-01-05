#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long stick[40];
long long ans;
vector<vector<long long> > stick_sum;

void count1(int i, int limit, int k, long long sum, int taken){
    if(i == limit){
        stick_sum[taken].push_back(sum);
        return;
    }

    if(taken == k-1 && stick[i] < sum) ans++;

    count1(i+1, limit, k, sum+stick[i], taken+1);
    count1(i+1, limit, k, sum, taken);
}

void count2(int i, int limit, int k, long long sum, int taken){
    if(i == limit) return;

    // if i is the largest stick
    // Case 1: internal
    if(taken == k-1 && stick[i] < sum) ans++;

    // Case 2: extrenal
    if(taken < k-1){
        int take_more = k-taken-1;
        // sum_more + sum > stick[i]
        // sum_more > stick[i] - sum
        long long sum_more = stick[i]-sum;

        ans += stick_sum[take_more].end()-upper_bound(stick_sum[take_more].begin(), stick_sum[take_more].end(), sum_more);
    }


    count2(i+1, limit, k, sum+stick[i], taken+1);
    count2(i+1, limit, k, sum, taken);
}

int main(){
    int tc;
    cin >> tc;
    for(int tc_num = 1; tc_num <= tc; tc_num++){
        int n, k;
        ans = 0;
        cin >> n >> k;
        stick_sum.assign(40, vector<long long>());

        for(int i = 0; i < n; i++){
            cin >> stick[i];
        }
        sort(stick, stick+n);

        if(n <= 15){
            count1(0, n, k, 0, 0);
        }
        else{
            count1(0, 15, k, 0, 0);

            for(int i = 0; i < 35; i++){
                sort(stick_sum[i].begin(), stick_sum[i].end());
            }

            count2(15, n, k, 0, 0);
        }

        cout << "Case " << tc_num << ": " << ans << endl;
    }

    return 0;
}