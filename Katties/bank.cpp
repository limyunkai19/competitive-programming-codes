#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

vector<ii> money;

bool occupied[100];

int main(){
    int n, close, m, t;
    cin >> n >> close;

    for(int i = 0; i < n; i++){
        cin >> m >> t;
        money.push_back(ii(m, t));
    }

    sort(money.begin(), money.end(), greater<ii>() );

    int ans = 0, taken = 0;
    for(int i = 0; i < money.size(); i++){
        for(int j = money[i].second; j >= 0; j--){
            if(!occupied[j]){
                occupied[j] = true;
                ans += money[i].first;
                break;
            }
        }
    }

    cout << ans << endl;


    return 0;
}