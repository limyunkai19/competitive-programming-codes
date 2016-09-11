// approach 2, dijkstra

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int n, a[20];

int switch_bit(int state, int bit){
    if(state & 1<<bit){
        // it is a 1, need change to 0
        return ~(switch_bit(~state, bit));
    }
    else{
        // it is a 0, need change to 1
        return (state | 1<<bit);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    vector<int> dist(1<<(n+1), 1<<30);
    dist[(1<<(n+1))-1] = 0;
    pq.push(ii(0, (1<<(n+1))-1));

    while(!pq.empty()){
        int state = pq.top().second, d = pq.top().first;
        pq.pop();
        if(dist[state] != d)
            continue;

        int cloth_pos = state%2;
        for(int i = 1; i <= n; i++){
            //      1               1                  0                 0
            if((cloth_pos && (state & 1<<i)) || (!cloth_pos && (~state & 1<<i)) ){
                // for each person, try go alone
                int next_state = switch_bit(state, 0);
                next_state = switch_bit(next_state, i);
                if(dist[state] + a[i] < dist[next_state]){
                    dist[next_state] = dist[state] + a[i];
                    pq.push(ii(dist[next_state], next_state));
                }
                // now bring another person
                for(int j = i+1; j <= n; j++){
                    if( (cloth_pos && (state & 1<<j)) || (!cloth_pos && (~state & 1<<j)) ){
                        int next_state2 = switch_bit(next_state, j);
                        if(dist[state] + max(a[i], a[j]) < dist[next_state2]){
                            dist[next_state2] = dist[state] + max(a[i], a[j]);
                            pq.push(ii(dist[next_state2], next_state2));
                        }
                    }
                }
            }
        }
    }


    cout << dist[0] << endl;

    return 0;
}