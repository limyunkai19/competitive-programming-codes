#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int tree[100100];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tree[i];
    }
    sort(tree, tree+n, greater<int> () );
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, tree[i]+i);
    }
    cout << ans+2 << endl;
    return 0;
}