#include <iostream>
#include <algorithm>
#include <vector>

#define mod 1000000007

using namespace std;

int main(){
    long long n, limit;
    long long penalty = 0, solved = 0;
    cin >> n >> limit;

    long long a, b, c, t;
    cin >> a >> b >> c >> t;

    long long now = 0;

    vector<int> questions;
    questions.push_back(t);

    for(int i = 1; i < n; i++){
        questions.push_back(    t = ((a*t + b)%c)+1    );
    }

    sort(questions.begin(), questions.end());

    for(int i = 0; solved < n && now + questions[i] <= limit; i++, solved++){
        now += questions[i];
        penalty = (penalty+now)%mod;
    }

    cout << solved << ' ' << penalty << endl;

    return 0;
}