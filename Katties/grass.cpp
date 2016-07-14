#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<double, double> dd;

double w, limit;

dd compute_pair(double x, double r){
    double offset = sqrt(r*r - w*w);
    return dd(x-offset, x+offset);
}

int main(){
    int n;
    while(cin >> n >> limit >> w){
        w /= 2;

        vector<dd> lr;

        while(n--){
            int x, r;
            cin >> x >> r;
            if(r < w) continue;
            lr.push_back(compute_pair(x, r));
        }

        sort(lr.begin(), lr.end());
        // important, used to skip tedious boundary check after the for loop
        // like next furthest < goal etc
        lr.push_back(dd(1e20, 0));

        double cur = 0, next_furthest = lr[0].first;
        int ans = 0;
        for(int i = 0; i < lr.size(); i++){
            double l = lr[i].first, r = lr[i].second;
            // goal state reached
            if(next_furthest >= limit){
                ans++;
                break;
            }
            // big gap (tendency of failing notice this condition)
            if(l > next_furthest){
                ans = -1;
                break;
            }
            if(l > cur){
                // no advancement
                if(next_furthest == cur){
                    ans = -1;
                    break;
                }
                else{
                    cur = next_furthest;
                    ans++;
                }
            }
            next_furthest = max(r, next_furthest);
        }
        cout << ans << endl;
    }

    return 0;
}