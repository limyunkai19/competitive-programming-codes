#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int encode[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};
    string name;
    int pre;
    while(cin >> name){
        pre = 0;
        for(int i = 0; i < name.size(); i++){
            if(encode[name.at(i) - 'A'] > 0 && encode[name.at(i) - 'A'] != pre){
                printf("%d", encode[name.at(i) - 'A']);
            }
            pre = encode[name.at(i) - 'A'];
        }
        printf("\n");
    }
    return 0;
}

