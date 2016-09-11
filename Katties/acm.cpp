#include <iostream>

using namespace std;

int problem_attempt[30];

int main(){
    int minutes, score = 0, penalty = 0;
    char problem;
    string verdict;

    while(cin >> minutes >> problem >> verdict && minutes != -1){
        if(verdict[0] == 'r'){
            score++;
            penalty += minutes + problem_attempt[problem-'A'];
        }
        else{
            problem_attempt[problem-'A'] += 20;
        }
    }
    cout << score << ' ' << penalty << endl;
    return 0;
}