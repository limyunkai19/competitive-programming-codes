/*
ID: yunkai91
PROG: frameup
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

char frame[50][50];
int x1[50], x2[50], y1[50], y2[50];
bool taken[50];
vector<char> ans;
vector<string> all_ans;

bool isValid(int i, int j, int id){
    if(frame[i][j] == '.' || frame[i][j] -'A' == id)
        return true;
    return taken[frame[i][j]-'A'];
}

bool cantake(int id){
    for(int i = x1[id]; i <= x2[id]; i++){
        if(!isValid(i, y1[id], id) || !isValid(i, y2[id], id))
            return false;
    }
    for(int i = y1[id]; i <= y2[id]; i++){
        if(!isValid(x1[id], i, id) || !isValid(x2[id], i, id))
            return false;
    }
    return true;
}

void findSolution(){
    bool alltaken = true;
    for(int i = 0; i < 30; i++){
        if(!taken[i] && cantake(i)){
            ans.push_back(i+'A');
            taken[i] = true;

            findSolution();

            ans.pop_back();
            taken[i] = false;

            alltaken = false;
        }
    }

    if(alltaken){
        all_ans.push_back(string(ans.rbegin(), ans.rend()));
    }
}

int main(){
    freopen("frameup.in", "r", stdin);
    freopen("frameup.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < 40; i++) taken[i] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> frame[i][j];

            if(frame[i][j] != '.'){
                int id = frame[i][j] - 'A';
                if(x2[id] == 0){
                    x1[id] = x2[id] = i;
                    y1[id] = y2[id] = j;
                    taken[id] = false;
                }
                else{
                    x1[id] = min(x1[id], i);
                    x2[id] = max(x2[id], i);
                    y1[id] = min(y1[id], j);
                    y2[id] = max(y2[id], j);
                }
            }
        }
    }

    findSolution();
    sort(all_ans.begin(), all_ans.end());
    for(int i = 0; i < all_ans.size(); i++)
        cout << all_ans[i] << '\n';

    return 0;
}