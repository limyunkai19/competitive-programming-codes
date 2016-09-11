#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        set<string> s;
        vector<string> v(n);

        for(int i = 0; i < n; i++){
            cin >> v[i];
            s.insert(v[i]);
        }

        int valid = true;
        for(int i = 0; i < n && valid; i++){
            string tmp = "";
            for(int j = 0; j < v[i].size()-1; j++){
                tmp += v[i][j];
                if(s.count(tmp)){
                    valid = false;
                }
            }
        }

        if(valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}