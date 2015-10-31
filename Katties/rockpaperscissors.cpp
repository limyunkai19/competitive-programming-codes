#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int win[150], lose[150];

int winner(string m1, string m2){
    if(m1 == "rock"){
        if(m2 == "scissors"){
            return 1;
        }
        if(m2 == "paper"){
            return 2;
        }
        return 0;
    }
    if(m1 == "paper"){
        if(m2 == "scissors"){
            return 2;
        }
        if(m2 == "rock"){
            return 1;
        }
        return 0;
    }
    if(m1 == "scissors"){
        if(m2 == "paper"){
            return 1;
        }
        if(m2 == "rock"){
            return 2;
        }
        return 0;
    }
}

int main(){
    int n, k;
    int p1, p2;
    string m1, m2;
    bool first = true;;
    while(cin >> n >> k && n != 0){
        if(first){
            first = false;
        }
        else{
            cout << endl;
        }
        memset(win, 0, sizeof win);
        memset(lose, 0, sizeof lose);
        for(int i = 0; i < (k*n*(n-1))/2; i++){
            cin >> p1 >> m1 >> p2 >> m2;
            if(winner(m1, m2) == 1){
                win[p1]++;
                lose[p2]++;
            }
            else if(winner(m1, m2) == 2){
                win[p2]++;
                lose[p1]++;
            }
        }
        for(int i = 1; i <= n; i++){
            double winrate = win[i];
            if(win[i]+lose[i] == 0){
                printf("-\n");
            }
            else{
                winrate /= win[i]+lose[i];
                printf("%0.3lf\n", winrate);
            }
        }
    }
    return 0;
}