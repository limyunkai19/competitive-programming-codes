#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool is_abd[28200];
vector<int> abd;

int count_div(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n%i == 0){
            sum += i;
        }
    }
    return sum;
}

int main()
{
    memset(is_abd, false, sizeof is_abd);
    for(int i = 11; i < 28150; i++){
        if(count_div(i) > i){
            is_abd[i] = true;
            abd.push_back(i);
        }
    }
    int sum = 0;
    for(int i = 1; i < 28150; i++){
        for(int j = 0; j < abd.size(); j++){
            if(abd[j] > i){
                sum += i;
                break;
            }
            else if(is_abd[i - abd[j]]){
                break;
            }
        }
    }
    cout << sum << endl;

    return 0;
}
