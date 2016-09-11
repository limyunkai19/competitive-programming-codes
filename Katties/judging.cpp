#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    string x;
    multiset<string> s;
    multiset<string>::iterator it;

    for(int i = 0; i < n; i++){
        cin >> x;
        s.insert(x);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        it = s.find(x);
        if(it != s.end()){
            ans++;
            s.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}