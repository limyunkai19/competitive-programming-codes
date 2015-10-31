/*
ID: yunkai91
LANG: C++
TASK: sort3
*/

#include <iostream>
#include <cstdio>

using namespace std;

int a[1010];

int main(){
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    int n, cnt[4] = {0};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int twoinone = 0, threeinone = 0, oneintwo = 0, threeintwo = 0, twointhree = 0, oneinthree = 0;
    for(int i = 0; i < cnt[1]; i++){
        if(a[i] == 2) twoinone++;
        if(a[i] == 3) threeinone++;
    }
    for(int i = cnt[1], j = 0; j < cnt[2]; i++, j++){
        if(a[i] == 1) oneintwo++;
        if(a[i] == 3) threeintwo++;
    }
    for(int i = cnt[1]+cnt[2], j = 0; j < cnt[3]; i++, j++){
        if(a[i] == 1) oneinthree++;
        if(a[i] == 2) twointhree++;
    }

    int swap = 0;
    //swap all 1 to 1 places first
    if(oneintwo > twoinone){
        swap += oneintwo;
        swap += oneinthree;
        oneintwo -= twoinone;
        threeintwo += oneintwo;
        swap += threeintwo;
    }
    else{ // one in three > three in one
        swap += oneintwo;
        swap += oneinthree;
        oneinthree -= threeinone;
        twointhree += oneinthree;
        swap += twointhree;
    }

    cout << swap << endl;

    return 0;
}