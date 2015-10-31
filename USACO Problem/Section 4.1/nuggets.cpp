/*
ID: yunkai91
LANG: C++
TASK: nuggets
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int a[20];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);

    int n, allgcd;
    priority_queue<int, vector<int>, greater<int> > pq;
    map<int, bool> visited;
    cin >> n;
    cin >> a[0];
    allgcd = a[0];
    pq.push(a[0]);
    for(int i = 1; i < n; i++){
        cin >> a[i];
        allgcd = gcd(allgcd, a[i]);
        pq.push(a[i]);
    }
    sort(a, a+n);
    if(a[0] == 1 || allgcd != 1){
        cout << 0 << endl;
        return 0;
    }

    int consecutive = 0, pre = 0;
    while(!pq.empty()){
        int k = pq.top(); pq.pop();
        if(k == pre+1){
            consecutive++;
        }
        else{
            consecutive = 1;
        }
        pre = k;
        if(consecutive == a[0]){
            break;
        }
        for(int i = 0; i < n; i++){
            if(!visited[k+a[i]]){
                visited[k+a[i]] = true;
                pq.push(k+a[i]);
            }
        }
    }
    cout << pre-a[0] << endl;

    return 0;
}
