#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<double, double> dd;
typedef pair<dd, int> ddi;

int main(){
    double A, B, a, b;
    int n;
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

        // stupid special case
        if(A == B){
            int i;
            for(i = 0; i < interval.size(); i++){
                double l = interval[i].first.first, r = interval[i].first.second;
                if(l <= A && B <= r){
                    cout << 1 << endl;
                    cout << interval[i].second << endl;
                    break;
                }
            }
            if(i == interval.size()){
                cout << "impossible" << endl;
            }
            continue;
        }

        // dont use weird algorithm
        // among those interval whose start <= A, choose the one with furthest end
        // make A = furthest end;
        // break when A >= B
        // impossible when furthest end == A OR A < B at the end

        int i = 0;
        while(i < interval.size() && A < B){
            int idx = -1;
            double furthest_end = A;

            // for each interval with l < A, choose best r
            for(;i < interval.size(); i++){
                double l = interval[i].first.first, r = interval[i].first.second;
                if(l > A){
                    i--;
                    break;
                }
                // candidate interval (l < A)
                if(r > furthest_end){
                    // best so far
                    idx = interval[i].second;
                    furthest_end = r;
                }
            }

            if(idx == -1){
                // no interval found, a gap
                // invarient A < B remain
                break;
            }

            used.push_back(idx);
            A = furthest_end;
        }

        if(A < B){
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