#include <iostream>
#include <cstring>

using namespace std;

#define start (n)
#define end (n+1)
#define INF (1<<28)

int min_time[1<<22][22], dist[22][22], point[22], time_needed[22], deadline[22];
int n, time_limit, ans, ans_state;

int next_bit(unsigned int v){
    unsigned int t = v | (v - 1);
    return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}

int flip_bit(int x){
    int ret = 0;
    for(int i = 0; i < n+1; i++){
        ret = ret*2 + x%2;
        x /= 2;
    }
    return ret;
}
void update_ans(int state){
    int this_ans = 0;
    for(int i = 0; i < n; i++){
        if(state & (1<<i))
            this_ans += point[i];
    }

    if(this_ans > ans){
        ans = this_ans;
        ans_state = state;
    }
    else if(this_ans == ans){
        if(flip_bit(ans_state) < flip_bit(state)){
            ans_state = state;
        }
    }
}

int main(){
    cin >> n >> time_limit;

    for(int i = 0; i < n; i++){
        cin >> point[i] >> time_needed[i] >> deadline[i];
        if(deadline[i] == -1)
            deadline[i] = INF;
    }

    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+2; j++){
            cin >> dist[i][j];

            // i to j, j need to be completed
            dist[i][j] += time_needed[j];
        }
    }

    // fill base case
    memset(min_time, 1, sizeof min_time);
    for(int i = 0; i < n; i++){
        if(dist[start][i] <= deadline[i])
            min_time[1<<i][i] = dist[start][i];
    }

    ans = 0;
    for(int bit_num = 1; bit_num <= n; bit_num++){
        int bit = (1<<bit_num)-1;
        for(int state = bit; state < (1<<n); state = next_bit(state)){
            for(int last = 0; last < n; last++){
                if(min_time[state][last] <= time_limit){
                    // test see if this can be a solution
                    if(min_time[state][last] + dist[last][end] <= time_limit)
                        update_ans(state);

                    // update others state
                    for(int next = 0; next < n; next++){
                        //    not visited                           can visit (within deadline)
                        if(~state & (1<<next) && min_time[state][last] + dist[last][next] <= deadline[next]){
                            int next_state = state | (1<<next);
                            min_time[next_state][next] = min(min_time[next_state][next], min_time[state][last] + dist[last][next]);
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    if(ans != 0){
        for(int i = 0; i < n; i++){
            if(ans_state & (1<<i))
                cout << i+1 << ' ';
        }
    }
    cout << endl;

    return 0;
}