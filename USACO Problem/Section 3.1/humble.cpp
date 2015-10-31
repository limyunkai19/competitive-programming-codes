/*
ID: yunkai91
LANG: C++
TASK: humble
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int prime[110];

int main(){
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);

    priority_queue<long long, vector<long long>, greater<long long> > pq;
    map<long long, bool> visited;
    long long n, k, small, largestinqueue = 0;
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> prime[i];
        pq.push(prime[i]);
        visited[prime[i]*small] = true;
    }
    sort(prime, prime+k);
    while(n){
        small = pq.top(); pq.pop();
        n--;
        for(int i = 0; i < k; i++){
            if(pq.size() > n && prime[i]*small > largestinqueue)
                break;
            if(!visited[prime[i]*small]){
                pq.push(prime[i]*small);
                largestinqueue = max(largestinqueue, prime[i]*small);
                visited[prime[i]*small] = true;
            }
        }
    }
    cout << small << endl;

    return 0;
}