#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char qoute;
    char l = '`', r = '\'';
    int place = 1;
    qoute = getchar();
    while(qoute != EOF){
        if(qoute == '"'){
            if(place > 0){
                putchar(l);
                putchar(l);
                place *= (-1);
            }
            else{
                putchar(r);
                putchar(r);
                place *= (-1);
            }
        }
        else{
            putchar(qoute);
        }
        qoute = getchar();
    }
    return 0;
}
