#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a, b, a_max = 0, b_max = 0;

        for(int i = 0; i < n; i++){
            cin >> a;
            a_max = max(a_max, a);
        }
        for(int i = 0; i < m; i++){
            cin >> b;
            b_max = max(b_max, b);
        }

        if(a_max >= b_max)
            cout << "Godzilla" << endl;
        else
            cout << "MechaGodzilla" << endl;

    }

    return 0;
}