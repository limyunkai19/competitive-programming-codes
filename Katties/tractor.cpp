#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> ii;

vector<ii> points;

int main(){
    points.push_back(ii(0, 1));
    long long now = 0;
    for(long long step = 1; now < 100000000; step *= 2){
        now += step;
        points.push_back(ii(now, step*2+points[points.size()-1].second));
    }

    long long n, a, b, ans;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        vector<ii>::iterator it = lower_bound(points.begin(), points.end(), ii(a, 10000000000000000LL));
        it--;
        now = it->first;
        ans = it->second;
        it++;
        if(b <= (it->first))
            cout << ( ans+a-now+b-now ) << endl;
        else{
            int cangrow = a+1;
            ans += cangrow;
            int growfactor = (it->first)+1;
            now = (it->first);
            while(now < b){
                //cout << now << ' ' << ans << endl;
                ans += cangrow;
                now += growfactor;
                growfactor *= 2;
            }
            //overshoot
            if(now-a <= b)
                ans -= (now-b);
            else
                ans -= cangrow;
            cout << ans << endl;
        }
    }

    return 0;
}
