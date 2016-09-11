#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, string> ls;

long long to_number(string rank){
    // encode in base 3
    long long ans = 0, power = 1, equal = 0;
    bool pre_e = true;
    for(int i = 0; i < rank.size(); i++){
        if(pre_e){
            if(rank[i] == 'u'){
                ans += power*2;
            }
            else if(rank[i] == 'm'){
                ans += power;
            }
            power *= 3;
            equal++;
            pre_e = false;
        }
        if(rank[i] == '-'){
            pre_e = true;
        }
    }
    while(equal <= 10){
        ans *= 3;
        ans++;
        equal++;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ls> person;
        for(int i = 0; i < n; i++){
            string s, rank;
            cin >> s >> rank;
            person.push_back(ls(-to_number(rank), s));
            cin >> rank;
        }
        sort(person.begin(), person.end());
        for(int i = 0; i < n; i++){
            string s = person[i].second;
            for(int j = 0; j < s.size()-1; j++){
                cout << s[j];
            }
            cout << endl;
        }
        cout << "==============================" << endl;
    }


    return 0;
}