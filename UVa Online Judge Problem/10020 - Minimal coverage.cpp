#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main(){
    int tc;
    cin >> tc;
    bool first = true;
    while(tc--){
        if(!first) cout << endl;
        first = false;

        int m, l, r;
        cin >> m;
        vector<ii> interval, ans;
        while(cin >> l >> r && !(l == 0 && r == 0)){
            interval.push_back(ii(l, r));
        }
        sort(interval.begin(), interval.end());

        bool complete = false;
        int far = 0, nextfar = 0, lnextfar;
        for(int i = 0; i < interval.size(); i++){
            int l = interval[i].first, r = interval[i].second;
            if(l > far){
                far = nextfar;
                ans.push_back(ii(lnextfar, nextfar));
            }
            if(l > nextfar){
                break;
            }
            if(r > nextfar){
                lnextfar = l;
                nextfar = r;
            }
            if(nextfar >= m){
                ans.push_back(ii(lnextfar, nextfar));
                complete = true;
                break;
            }
        }
        if(!complete){
            cout << 0 << endl;
        }
        else{
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i].first << ' ' << ans[i].second << endl;
            }
        }
    }

    return 0;
}