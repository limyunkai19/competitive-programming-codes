/*
ID: yunkai91
LANG: C++
TASK: hamming
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, bit, dist;
bool ansfound = false;
vector<int> ans;

int hammingdist(int x, int y){
    int thisdist = 0;
    for(int i = 0, mask = 1; i < 10; i++, mask = mask << 1){
        int a = x&mask, b = y&mask;
        if(a != b) thisdist++;
    }
    return thisdist;
}

bool canuse(int x){
    for(int i = 0; i < ans.size(); i++){
        if(hammingdist(x, ans[i]) < dist){
            return false;
        }
    }
    return true;
}

void findans(int num, int nextnum){
    if(num == n){
        ansfound = true;
        return;
    }
    while(!ansfound){
        while(!canuse(nextnum)) nextnum++;
        ans.push_back(nextnum);
        findans(num+1, nextnum+1);
        if(!ansfound) ans.pop_back();
    }
}

int main(){
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

    cin >> n >> bit >> dist;

    findans(0, 0);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i == n-1){
            cout << endl;
        }
        else if(i%10 == 9){
            cout << endl;
        }
        else{
            cout << ' ';
        }
    }

    return 0;
}