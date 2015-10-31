#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int encode[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};
    string name;
    int num_left, pre;
    printf("         NAME                     SOUNDEX CODE\n");
    while(cin >> name){
        num_left = 3;
        printf("         ");
        cout << name;
        for(int i = 0; i < 25-name.size(); i++){
            printf(" ");
        }
        printf("%c", name.at(0));
        for(int i = 1; i < name.size(); i++){
            pre = encode[name.at(i-1) - 'A'];
            if(encode[name.at(i) - 'A'] > 0 && encode[name.at(i) - 'A'] != pre){
                printf("%d", encode[name.at(i) - 'A']);
                pre = encode[name.at(i) - 'A'];
                num_left--;
            }
            if(num_left <= 0){
                break;
            }
        }
        while(num_left > 0){
            printf("0");
            num_left--;
        }
        printf("\n");
    }
    printf("                   END OF OUTPUT\n");
    return 0;
}
