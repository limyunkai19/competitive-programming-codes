#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> tower(n);
    for(int i = 0; i < n; i++){
        cin >> tower[i];
    }
    sort(tower.begin(), tower.end());
    int ans = n;
    for(int i = 0; i < tower.size(); i++){
        ans = min(ans, tower[i]+n-1-i);
    }
    cout << ans << endl;
    return 0;
}