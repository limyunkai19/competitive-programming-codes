/*
ID: yunkai91
LANG: C++
TASK: job
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

multiset<int> pendingb, testb;
vector<int> btime;

bool possible(int t){
    testb = pendingb;
    for(int i = 0; i < btime.size(); i++){
        int now = t;
        while(now-btime[i] > 0){
            multiset<int>::iterator bjob = testb.upper_bound(now-btime[i]);
            bjob--;
            if(*bjob == -300){
                break;
            }
            else{
                now -= btime[i];
                testb.erase(bjob);
            }
        }
    }
    return testb.size() == 1;
}

int main(){
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);

    int n, a, b, x;
    cin >> n >> a >> b;

    priority_queue<ii, vector<ii>, greater<ii> > acomplete;

    for(int i = 0; i < a; i++){
        cin >> x;
        acomplete.push(ii(x, x));
    }
    for(int i = 0; i < b; i++){
        cin >> x;
        btime.push_back(x);
    }

    sort(btime.rbegin(), btime.rend());

    int aans, an = n;
    pendingb.insert(-300);
    while(an > 0){
        int timefin = acomplete.top().first;
        x = acomplete.top().second;
        acomplete.pop();
        an--;
        pendingb.insert(timefin);
        acomplete.push(ii(timefin+x, x));
        aans = timefin;
    }
    cout << aans << ' ';

    int hi = 50000, lo = 1;
    while(hi > lo){
        int mid = (hi+lo)/2;
        if(possible(mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }

    cout << hi << endl;
    return 0;
}