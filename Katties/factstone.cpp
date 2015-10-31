#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<double> digit;

int main(){
    double limit = (1<<23);
    digit.push_back(0);
    double last = 0;
    for(int i = 2; last < limit; i++){
        last += log2(i);
        digit.push_back(last);
    }

    int year;
    while(cin >> year && year != 0){
        limit = (4<< ((year-1960)/10) );
        for(int i = 0; i < digit.size(); i++){
            if(digit[i] > limit){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}