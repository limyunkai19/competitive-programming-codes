#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int r, n, deg, minute, sec;
        cin >> r >> n;
        cin >> deg >> minute >> sec;
        sec += 60*minute + 60*60*deg;
        set<int> slice;
        int now = 0;
        while(slice.count(now) == 0 && n--){
            slice.insert(now);
            now += sec;
            if(now >= 360*60*60) now -= 360*60*60;
        }
        int largest = 360*60*60 - *(--slice.end());
        int pre = *(slice.begin());
        for(set<int>::iterator it = ++slice.begin(); it != slice.end(); it++){
            largest = max(largest, *it - pre);
            pre = *it;
        }
        printf("%0.7lf\n", acos(-1)*r*r*largest/360.0/60.0/60.0);
    }

    return 0;
}