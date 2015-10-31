#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> t1;
vector<int> t2;
vector<int> t3;

void printv(vector<int> k){
    for(int i = k.size()-1; i >= 0; i--){
        cout << k[i];
    }
    cout << endl;
}

int main()
{
    int term = 3, sz;
    t1.push_back(1);
    t2.push_back(1);
    t3.push_back(2);
    while(t3.size() <= 999){
        t1 = t2;
        t2 = t3;
        sz = t1.size();
        for(int i = 0; i < sz; i++){
            t3[i] += t1[i];
        }
        for(int i = 0; i < t3.size(); i++){
            if(t3[i] >= 10 && i != t3.size()-1){
                t3[i+1]++;
                t3[i]%= 10;
            }
        }
        if(t3[t3.size()-1] >= 10){
            t3.push_back(t3[t3.size()-1]/10);
            t3[t3.size()-2] %= 10;
        }
        term++;
    }
    cout << term << endl;
    return 0;
}
