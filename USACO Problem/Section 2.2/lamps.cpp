/*
ID: yunkai91
LANG: C++
TASK: lamps
*/

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main(){
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    int n, c;
    cin >> n >> c;

    string init = "";
    for(int i = 0; i < n; i++) init += '1';
    map<string, vector<int> > possible;
    map<string, vector<int> >::iterator it;

    int start[4] = {0, 0, 1, 0};
    int steps[4] = {1, 2, 2, 3};

    for(int i = 0; i < (1<<4); i++){
        string newstat = init;
        int pressed = 0;
        for(int mask = 1, j = 0; j < 4; j++, mask = mask<<1){
            if(mask&i){ //button is pressed;
                pressed++;
                for(int k = start[j]; k < newstat.size(); k+=steps[j]){
                    //change this lamp state
                    if(newstat[k] == '0')   newstat[k] = '1';
                    else                    newstat[k] = '0';
                }
            }
        }
        possible[newstat].push_back(pressed);
    }

    vector<int> onlamp, offlamp;
    int x;
    while(cin >> x && x != -1) onlamp.push_back(--x);
    while(cin >> x && x != -1) offlamp.push_back(--x);

    bool ans = false;
    for(it = possible.begin(); it != possible.end(); it++){
        vector<int> possiblestep = it->second;
        string thisstate = it->first;

        bool canuse = true;
        for(int i = 0; i < onlamp.size(); i++){
            if(thisstate[onlamp[i]] == '0'){
                canuse = false;
                break;
            }
        }
        for(int i = 0; i < offlamp.size(); i++){
            if(thisstate[offlamp[i]] == '1'){
                canuse = false;
                break;
            }
        }

        if(!canuse) continue;

        for(int i = 0; i < possiblestep.size(); i++){
            if(c >= possiblestep[i] && possiblestep[i]%2 == c%2){
                cout << thisstate << endl;
                ans = true;
            }
        }
    }

    if(!ans){
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}