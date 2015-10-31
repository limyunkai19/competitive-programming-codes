#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int height, node = 1;
    char step;
    cin >> height;
    while(cin >> step){
        if(step == 'L'){
            node = node*2;
        }
        else{
            node = node*2 + 1;
        }
    }
    cout << ((2<<height)-node) << endl;
}