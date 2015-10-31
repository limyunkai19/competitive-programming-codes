#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    freopen("shufflein.txt", "r", stdin);
    freopen("shuffleout.txt", "w", stdout);

    deque<ii> q;
    int n, c, a, m, low;
    vector<ii> pos;
    vector<int> minister;
    //set<int> standing;
    cin >> n >> c;
    m = c+1;
    //vector<int> chair;
    cin >> low;
    pos.push_back(ii(low, 1));
    for(int i = 1; i < c; i++){
        cin >> a;
        //chair.push_back(a);
        pos.push_back(ii(a, 1));
    }
    for(int i = 0; i < m; i++){
        cin >> a;
        minister.push_back(a);
        //standing.insert(a);
        pos.push_back(ii(a, 0));
    }
    sort(pos.begin(), pos.end());
    for(int i = pos.size()-1; i >= 0; i--){
        if(q.empty()){
            q.push_back(pos[i]);
        }
        else if(q.back().second == 1 && pos[i].second == 0){
            if(q.back().first == low){
                a = pos[i].first;
            }
            q.pop_back();
        }
        else{
            q.push_back(pos[i]);
        }
    }
    while(q.size() > 1){
        if(q.front().second == 0 && q.back().second == 1){
            if(q.back().first == low){
                a = q.front().first;
            }
            q.pop_back();
            q.pop_front();
        }
        else{
            q.push_back(q.front());
            q.pop_front();
        }
    }
    cout << lower_bound(minister.begin(), minister.end(), a) - minister.begin() + 1<< endl;
    cout << lower_bound(minister.begin(), minister.end(), q.front().first) - minister.begin() + 1 << endl;

    /*int test = -1;
    int idx, acc, man = 0, b;
    for(int i = 0; i < pos.size(); i++){
        if(pos[i].second == 1){
            idx = (i-1+pos.size())%pos.size();
            acc = 0;
            while(!(acc == 0 && pos[idx].second == 0)){
                if(pos[idx].second == 1){
                    acc++;
                }
                else{
                    acc--;
                }
                idx = (idx-1)%pos.size();
            }
            if(man == 0){
                man = pos[idx].first;
            }
            standing.erase(pos[idx].first);
        }
    }
    cout << lower_bound(minister.begin(), minister.end(), man) - minister.begin() + 1<< endl;
    cout << lower_bound(minister.begin(), minister.end(), *standing.begin()) - minister.begin() + 1 << endl;
    */

    /*int pm;
    vector<int> e;
    while(!chair.empty()){
        e.clear();
        for(set<int>::iterator it = standing.begin(); it != standing.end(); it++){
                if(chair.find(minister[*it]) != chair.end()){
                    if(minister[*it] == low){
                        pm = *it;
                    }
                    chair.erase(minister[*it]);
                    e.push_back(*it);
                }
                else{
                    minister[*it]++;
                    if(minister[*it] == n+1){
                        minister[*it] = 1;
                    }
                }
        }
        for(int i = 0; i < e.size(); i++){
            standing.erase(e[i]);
        }
    }
    cout << pm+1 << endl;
    cout << *standing.begin() + 1 << endl;
    */
    return 0;
}
