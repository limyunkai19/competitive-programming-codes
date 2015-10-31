#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isleap(int n){
    if(n%4 == 0){
        if(n%100 == 0){
            if(n%400 == 0){
                return true;
            }else{
                return false;
            }
        }else{
            return true;
        }
    }else{
        return false;
    }
}

int main()
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sunday = 0, day = 1;
    for(int i = 1; i <= 12; i++){
        day += days[i];
    }
    for(int year = 1901; year <= 2000; year++){
        for(int month = 1; month <= 12; month ++){
            if(day%7 == 0){
                sunday++;
            }
            if(month == 2 && isleap(year)){
                day++;
            }
            day += days[month];
        }
    }
    cout << sunday << endl;
    return 0;
}
