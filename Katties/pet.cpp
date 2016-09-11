#include <iostream>

using namespace std;

int main(){
    int winner = 0, score = 0;
    for(int i = 1; i <= 5; i++){
        int cur_score = 0;
        for(int j = 0; j < 4; j++){
            int x;
            cin >> x;
            cur_score += x;
        }
        if(cur_score > score){
            winner = i;
            score = cur_score;
        }
    }
    cout << winner << ' ' << cur_score << endl;
}