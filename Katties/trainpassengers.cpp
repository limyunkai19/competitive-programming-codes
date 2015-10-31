#include <iostream>

using namespace std;

int main(){
    int cap, n, train = 0, left, enter, wait;
    cin >> cap >> n;
    bool valid = true;
    while(n--){
        cin >> left >> enter >> wait;
        if(left > train) valid = false;
        train += enter - left;
        if(train > cap) valid = false;
        if(wait != 0 && train != cap) valid = false;
    }
    if(train != 0 || wait != 0) valid = false;
    if(valid)
        cout << "possible" << endl;
    else
        cout << "impossible" << endl;

}