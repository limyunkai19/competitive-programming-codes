/*
ID: yunkai91
LANG: C++
TASK: lgame
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;

int infre[30], letter[30] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
vector<string> valid, ans;

int score(string a){
    int thisfre[30] = {0}, s = 0;
    for(int i = 0; i < a.size(); i++){
        thisfre[a[i]-'a']++;
        if(thisfre[a[i]-'a'] > infre[a[i]-'a']){
            return 0;
        }
        s += letter[a[i]-'a'];
    }
    return s;
}

int main(){
    freopen("lgame.in", "r", stdin);
    freopen("lgame.out", "w", stdout);
    ifstream dict("lgame.dict");

    string in;
    cin >> in;
    for(int i = 0; i < in.size(); i++){
        infre[in[i]-'a']++;
    }
    string dictin;
    while(dict >> dictin){
        if(score(dictin)){
            valid.push_back(dictin);
        }
    }

    int maxscore = 0;
    for(int i = 0; i < valid.size(); i++){
        int s = score(valid[i]);
        if(s > maxscore){
            ans = vector<string> ();
            ans.push_back(valid[i]);
            maxscore = s;
        }
        else if(s == maxscore){
            ans.push_back(valid[i]);
        }
        for(int j = i; j < valid.size(); j++){
            int s = score(valid[i]+valid[j]);
            if(s > maxscore){
                ans = vector<string> ();
                ans.push_back(valid[i]+" "+valid[j]);
                maxscore = s;
            }
            else if(s == maxscore){
                ans.push_back(valid[i]+" "+valid[j]);
            }
        }
    }
    cout << maxscore << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}