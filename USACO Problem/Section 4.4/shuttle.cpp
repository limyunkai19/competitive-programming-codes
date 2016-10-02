/*
ID: yunkai91
PROG: shuttle
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;

map<ii, int> dist;
map<ii, ii> parent;
map<ii, int> move;

int n;
void printstate(ii state){
    string ans = "";
    for(int i = 0; i < 2*n; i++){
        if(state.second == i-1)
            ans += '_';
        if(state.first&(1<<i))
            ans += 'B';
        else
            ans += 'W';
    }
    if(state.second == 2*n-1)
        ans += '_';

    cout << string(ans.rbegin(), ans.rend()) << endl;
}

int main(){
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);

    cin >> n;

    // wwwbbb_ = -1
    // www_bbb = 2 (n-1)
    //     ^
    // b = 1, w = 0

    ii startstate = ii((1<<n)-1, n-1);
    ii goalstate = ii(startstate.first << n, n-1);

    dist[startstate] = 1;
    queue<ii> q;
    q.push(startstate);

    while(!q.empty() && dist[goalstate] == 0){
        ii state = q.front(); q.pop();
        int x, y;

        // generate next state
        // no backing up => (1 <-) (0 ->)
        // try wb_ -> _bw
        x = state.first&(1<<(state.second+1));
        y = state.first&(1<<(state.second+2));
        if(state.second < 2*n-2 && x && !y){
            ii nextstate = state;
            nextstate.second += 2;
            nextstate.first |= (1<<(state.second+2));
            nextstate.first &= ~(1<<(state.second+1));
            if(dist[nextstate] == 0){
                dist[nextstate] = dist[state]+1;
                move[nextstate] = state.second+3;
                parent[nextstate] = state;
                q.push(nextstate);
            }
        }

        // try w_ -> _w
        x = state.first&(1<<(state.second+1));
        if(state.second < 2*n-1 && !x){
            ii nextstate = state;
            nextstate.second++;
            if(dist[nextstate] == 0){
                dist[nextstate] = dist[state]+1;
                move[nextstate] = state.second+2;
                parent[nextstate] = state;
                q.push(nextstate);
            }
        }

        // try _b -> b_
        x = state.first&(1<<state.second);
        if(state.second >= 0 &&  x){
            ii nextstate = state;
            nextstate.second--;
            if(dist[nextstate] == 0){
                dist[nextstate] = dist[state]+1;
                move[nextstate] = state.second;
                parent[nextstate] = state;
                q.push(nextstate);
            }
        }

        // try _wb -> bw_
        x = state.first&(1<<(state.second-1));
        y = state.first&(1<<(state.second));
        if(state.second >= 1 &&  x && !y){
            ii nextstate = state;
            nextstate.second -= 2;
            nextstate.first |= (1<<(state.second));
            nextstate.first &= ~(1<<(state.second-1));
            if(dist[nextstate] == 0){
                dist[nextstate] = dist[state]+1;
                move[nextstate] = state.second-1;
                parent[nextstate] = state;
                q.push(nextstate);
            }
        }
    }
    ii state = goalstate;
    vector<int> ans;
    while(state != startstate){
        ans.push_back(move[state]);
        state = parent[state];
    }

    for(int i = 0; i < ans.size(); i++){
        cout << 2*n+1 - ans[ans.size()-1-i];
        if(i%20 == 19 || i == ans.size()-1) cout << endl;
        else           cout << ' ' ;
    }

    return 0;
}

/*

*/
