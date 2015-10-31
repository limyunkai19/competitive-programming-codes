#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool can[140];

vector<int> parti;

int main(){
    int w, n, x;
    cin >> w >> n;
    parti.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> x;
        parti.push_back(x);
    }
    parti.push_back(w);
    for(int i = 0; i < parti.size(); i++){
        for(int j = i+1; j < parti.size(); j++){
            can[parti[j]-parti[i]] = true;
        }
    }
    string del = "";
    for(int i = 0; i <= 100; i++){
        if(can[i]){
            cout << del << i;
            del = " ";
        }
    }
    cout << endl;
    return 0;
}