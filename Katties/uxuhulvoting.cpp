#include <iostream>
#include <vector>

using namespace std;

int preferences[110][8];

int flip(int state, int i){
    if(state & 1<<i){
        state -= 1<<i;
    }
    else{
        state += 1<<i;
    }
    return state;
}

int best(int state, int ppl, vector<int>& result){
    int ans = 10, best_state;
    for(int i = 0; i < 3; i++){
        int next_state = flip(state, i);
        int result_state = result[next_state];
        if( ans > preferences[ppl][result_state] ){
            ans = preferences[ppl][result_state];
            best_state = result_state;
        }
    }
    return best_state;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 8; j++)
                cin >> preferences[i][j];

        vector<int> pre, now;
        for(int i = 0; i < 8; i++){
            pre.push_back(i);
            now.push_back(i);
        }
        for(int i = n-1; i >= 0; i--){
            for(int state = 0; state < 8; state++){
                now[state] = best(state, i, pre);
            }
            pre = now;
        }

        for(int i = 2; i >= 0; i--){
            if(1<<i & now[0])
                cout << 'Y';
            else
                cout << 'N';
        }
        cout << endl;
    }

    return 0;
}