#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string sen;

int main()
{
    int word;
    bool consecutive;
    while(getline(cin, sen)){
        word = 0;
        consecutive = false;
        for(int i = 0; i < sen.size(); i++){
            if(isalpha(sen.at(i))){
                consecutive = true;
            }
            else if(consecutive){
                consecutive = false;
                word++;
            }
        }
        if(consecutive){
            word++;
        }
        cout << word << endl;
    }

    return 0;
}
