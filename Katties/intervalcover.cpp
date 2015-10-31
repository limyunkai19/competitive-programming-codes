#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<double, double> dd;
typedef pair<dd, int> ddi;

int main(){
    double A, B, a, b;
    int n, idx;
    vector<ddi> interval;
    vector<int> used;

    while(cin >> A >> B){
        cin >> n;
        interval.clear();
        used.clear();
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            interval.push_back(ddi(dd(a, b), i));
        }
        sort(interval.begin(), interval.end());
        if(A == B || interval[0].first.first > A){
            cout << 0 << endl;
            continue;
        }
        double far = A, nextfar = interval[0].first.second;
        idx = 0;
        bool hole = false;
        for(int i = 0; i < interval.size() && nextfar < B; i++){
            if(interval[i].first.first > far){
                if(interval[i].first.first > nextfar){
                    hole = true;
                    break;
                }
                far = nextfar;
                used.push_back(idx);
            }
            if(nextfar < interval[i].first.second){
                nextfar = interval[i].first.second;
                idx = interval[i].second;
            }
        }
        used.push_back(idx);

        if(nextfar < B || hole){
            cout << "impossible" << endl;
        }
        else{
            cout << used.size() << endl;
            cout << used[0];
            for(int i = 1; i < used.size(); i++){
                cout << ' ' << used[i];
            }
            cout << endl;
        }
    }
    return 0;
}