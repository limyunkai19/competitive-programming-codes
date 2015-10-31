#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string line;
    line.clear();
    char temp;
    temp = getchar();
    while(temp != EOF){
        if(temp == ' ' || temp == '\n'){
            if(!line.empty()){
                for(int i = line.size()-1; i >= 0; i--){
                    cout << line.at(i);
                }
                line.clear();
            }
            putchar(temp);
        }
        else{
            line += temp;
        }
        temp = getchar();
    }
    if(!line.empty()){
        for(int i = line.size()-1; i >= 0; i--){
            cout << line.at(i);
        }
        line.clear();
    }
    return 0;
}
