#include <iostream>

using namespace std;

int dice[105], number[7];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> dice[i];
        number[dice[i]]++;
    }

    int winner = 0, score = 0;
    for(int i = 1; i <= n; i++){
        if(number[dice[i]] == 1){
            if(dice[i] > score){
                score = dice[i];
                winner = i;
            }
        }
    }

    if(winner == 0)
        cout << "none" << endl;
    else
        cout << winner << endl;

    return 0;
}