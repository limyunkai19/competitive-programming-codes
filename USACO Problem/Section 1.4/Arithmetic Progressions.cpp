#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;

bitset<125010> isBisquare;
vector<int> Bisquare;
vector<ii> AP;

int M;

void generate(int M){
    isBisquare.reset();
    for(int p = 0; p <= M; p++){
        for(int q = p; q <= M; q++){
            if(!isBisquare[p*p + q*q]){
                isBisquare.set(p*p + q*q, true);
                Bisquare.push_back(p*p + q*q);
            }
        }
    }


}

bool test_AP(int i, int d, int n){
    int current = Bisquare[i];
    while(n--){
        if(current > 2*M*M){
            return false;
        }
        if(!isBisquare[current]){
            return false;
        }
        current += d;

    }
    return true;
}

int main()
{
    int n;
    cin >> n >> M;
    generate(M);
    sort(Bisquare.begin(), Bisquare.end());
    for(int i = 0; i < Bisquare.size(); i++){
        cout << Bisquare[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < Bisquare.size()-n; i++){
        for(int j = i+1; j < Bisquare.size(); j++){
            if(test_AP(i, Bisquare[j]-Bisquare[i], n)){
                AP.push_back(ii(Bisquare[j]-Bisquare[i], Bisquare[i]));
            }
        }
    }
    if(AP.size() == 0){
        cout << "NONE" << endl;
    }
    sort(AP.begin(), AP.end());
    for(int i = 0; i < AP.size(); i++){
        cout << AP[i].second << " " << AP[i].first << endl;
    }

    return 0;
}
