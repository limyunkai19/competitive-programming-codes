#include <iostream>

using namespace std;

int main(){
    int n, speed, hours, pre_hours = 0, miles;
    while(cin >> n && n != -1){
        miles = pre_hours = 0;
        for(int i = 0; i < n; i++){
            cin >> speed >> hours;
            miles += speed * (hours - pre_hours);
            pre_hours = hours;
        }
        cout << miles << " miles" << endl;
    }
    return 0;
}