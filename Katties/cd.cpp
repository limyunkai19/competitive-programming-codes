#include <iostream>

using namespace std;

int cds[1000010];

int main(){
    int n, m;
    while(cin >> n >> m && n != 0 && m != 0){
        for(int i = 0; i < n; i++)
            cin >> cds[i];

        int ans = 0, n_idx = 0;
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            while(cds[n_idx] < x && n_idx < n)
                n_idx++;
            if(x == cds[n_idx]){
                ans++;
                n_idx++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}