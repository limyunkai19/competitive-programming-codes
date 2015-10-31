#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    freopen("landin.txt", "r", stdin);
    freopen("landout.txt", "w", stdout);

    char city[1005][1005];
    int r, c, length = 0, maxlength = 0, x1, y1, x2, y2;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        length = 0;
        for(int j = 0; j < c; j++){
            cin >> city[i][j];
            if(city[i][j] == '.'){
                length++;
                if(length > maxlength){
                    maxlength = length;
                    x2 = j + 1;
                    x1 = x2 - length + 1;
                    y1 = y2 = i+1;
                }
            }
            else{
                length = 0;
            }
        }
    }
    for(int j = 0; j < c; j++){
        length = 0;
        for(int i = 0; i < r; i++){
            if(city[i][j] == '.'){
                length++;
                if(length > maxlength){
                    maxlength = length;
                    y2 = i + 1;
                    y1 = y2 - length + 1;
                    x1 = x2 = j + 1;
                }
            }
            else{
                length = 0;
            }
        }
    }

    cout << y1 << " " << x1 << " " << y2 << " " << x2 << endl;

    return 0;
}
