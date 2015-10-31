#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Team{
    int point;
    int win;
    int goal_diff;
    int goal;
    int game;
    string name;
    int tie;
    int lose;
    int against;

    /*Team(){
        point = 1; win = 0; goal_diff = 0; goal = 0; game = 0;
    }*/
}team[1010];

inline bool comp(Team a, Team b){
    if(a.point != b.point){
        return a.point > b.point;
    }
    else if(a.win != b.win){
        return a.win > b.win;
    }
    else if(a.goal_diff != b.goal_diff){
        return a.goal_diff > b.goal_diff;
    }
    else if(a.goal != b.goal){
        return a.goal > b.goal;
    }
    else if(a.game != b.game){
        return a.game < b.game;
    }
    else{
        string ta;
        string tb;
        ta = a.name;
        tb = b.name;
        for(int i = 0; i < ta.size(); i++){
            if(isalpha(ta.at(i))){
                ta.at(i) = toupper(ta.at(i));
            }
        }
        for(int i = 0; i < tb.size(); i++){
            if(isalpha(tb.at(i))){
                tb.at(i) = toupper(tb.at(i));
            }
        }
        return ta < tb;
    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    map<string, int> index;
    string a;
    string b;
    string temp;
    string tournament;
    int tc;
    char tp;
    int t, n, pta, ptb, i_a, i_b;
    cin >> tc; getchar();
    while(tc--){
        getline(cin, tournament);
        cout << tournament << endl;
        cin >> t; getchar();
        for(int i = 0; i < t; i++){
            getline(cin, temp);
            //cout << temp << endl;
            index[temp] = i;
            team[i].name = temp;
            team[i].point = 0; team[i].win = 0; team[i].goal_diff = 0; team[i].goal = 0; team[i].game = 0;
            team[i].tie = 0; team[i].lose = 0; team[i].against = 0;
        }
        cin >> n; getchar();
        for(int i = 0; i < n; i++){
            getline(cin, a, '#');
            cin >> pta >> tp >> ptb >> tp;
            getline(cin, b);
            //cout << a << " " << pta << " " << b << " " << ptb << endl;
            i_a = index[a];
            i_b = index[b];
            team[i_a].game++;
            team[i_b].game++;
            //cout << i_a << " " << i_b << endl;
            //cout << team[index[a]].name << " " << team[i_b].name << endl;
            if(pta > ptb){
                team[i_a].point += 3;
                team[i_a].win++;
                team[i_a].goal_diff += pta - ptb;
                team[i_b].goal_diff += ptb - pta;
                team[i_a].goal += pta;
                team[i_b].goal += ptb;
                team[i_b].lose++;
                team[i_a].against += ptb;
                team[i_b].against += pta;
            }
            else if(ptb > pta){
                team[i_b].point += 3;
                team[i_b].win++;
                team[i_a].goal_diff += pta - ptb;
                team[i_b].goal_diff += ptb - pta;
                team[i_a].goal += pta;
                team[i_b].goal += ptb;
                team[i_a].lose++;
                team[i_a].against += ptb;
                team[i_b].against += pta;
            }
            else{
                team[i_a].point++;
                team[i_b].point++;
                team[i_a].goal_diff += pta - ptb;
                team[i_b].goal_diff += ptb - pta;
                team[i_a].goal += pta;
                team[i_b].goal += ptb;
                team[i_a].tie++;
                team[i_b].tie++;
                team[i_a].against += ptb;
                team[i_b].against += pta;
            }
        }
        sort(team, team + t, comp);
        for(int i = 1; i <= t; i++){
            cout << i << ") " << team[i-1].name << " " << team[i-1].point << "p, " << team[i-1].game << "g ("
            << team[i-1].win << "-" << team[i-1].tie << "-" << team[i-1].lose << "), "
            << team[i-1].goal_diff << "gd (" << team[i-1].goal << "-" << team[i-1].against << ")\n";
        }
        if(tc){
            cout << "\n";
        }
    }

    return 0;
}
