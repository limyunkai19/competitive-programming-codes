#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    char tic[3][3];
    int x, o;
    bool islineo, islinex;
    for(int i = 0; i < n; i++){
        if(i != 0){
            cout << endl;
        }
        x = 0; o = 0; islineo = false; islinex = false;
        for(int k = 0; k < 3; k++){
            for(int l = 0; l < 3; l++){
                cin >> tic[k][l];
                if(tic[k][l] == 'X'){
                    x++;
                }
                else if(tic[k][l] == 'O'){
                    o++;
                }
            }
        }
        if(tic[0][0] == tic [0][1] && tic[0][0] == tic[0][2] && tic[0][0] != '.'){
            if(tic[1][0] == tic[1][1] && tic[1][1] == tic[1][2] && tic[1][1] != '.'){
                cout << "no";
                continue;
            }
            else if(tic[2][0] == tic[2][1] && tic[2][0] == tic[2][2] && tic[2][2] != '.'){
                cout << "no";
                continue;
            }
            if(tic[0][0] == 'O'){
                islineo = true;
            }
            else if(tic[0][0] == 'X'){
                islinex = true;
            }
        }
        else if(tic[1][0] == tic[1][1] && tic[1][1] == tic[1][2] && tic[1][1] != '.'){
            if(tic[2][0] == tic[2][1] && tic[2][0] == tic[2][2] && tic[2][2] != '.'){
                cout << "no";
                continue;
            }
            if(tic[1][0] == 'O'){
                islineo = true;
            }
            else if(tic[1][0] == 'X'){
                islinex = true;
            }
        }
        if(tic[0][0] == tic[1][0] && tic[0][0] == tic[2][0] && tic[0][0] != '.'){
            if(tic[0][1] == tic[1][1] && tic[0][1] == tic[2][1] && tic[1][1] != '.'){
                cout << "no";
                continue;
            }
            else if(tic[0][2] == tic [1][2] && tic[1][2] == tic[2][2] && tic[2][2] != '.'){
                cout << "no";
                continue;
            }
            if(tic[0][0] == 'O'){
                islineo = true;
            }
            else if(tic[0][0] == 'X'){
                islinex = true;
            }
        }
        else if(tic[0][1] == tic[1][1] && tic[0][1] == tic[2][1] && tic[1][1] != '.'){
            if(tic[0][2] == tic[1][2] && tic[1][2] == tic[2][2] && tic[2][2] != '.'){
                cout << "no";
                continue;
            }
            if(tic[0][1] == 'O'){
                islineo = true;
            }
            else if(tic[0][1] == 'X'){
                islinex = true;
            }
        }
        if(tic[0][2] == tic[1][2] && tic[1][2] == tic[2][2]){
            if(tic[2][2] == 'O'){
                islineo = true;
            }
            else if(tic[2][2] == 'X'){
                islinex = true;
            }
        }
        if(tic[2][0] == tic[2][1] && tic[2][0] == tic[2][2]){
            if(tic[2][2] == 'O'){
                islineo = true;
            }
            else if(tic[2][2] == 'X'){
                islinex = true;
            }
        }
        if(tic[0][0] == tic[1][1] && tic[1][1] == tic[2][2]){
            if(tic[1][1] == 'O'){
                islineo = true;
            }
            else if(tic[1][1] == 'X'){
                islinex = true;
            }
        }
        if(tic[0][2] == tic[1][1] && tic[2][0] == tic[1][1]){
            if(tic[1][1] == 'O'){
                islineo = true;
            }
            else if(tic[1][1] == 'X'){
                islinex = true;
            }
        }
        if(o > x){
            cout << "no";
            continue;
        }
        else if(o < x-1){
            cout << "no";
            continue;
        }
        else if(islineo && x != o){
            cout << "no";
            continue;
        }
        else if(islinex && x != o+1){
            cout << "no";
            continue;
        }
        else if(islineo && islinex){
            cout << "no";
            continue;
        }
        cout << "yes";
    }
    cout << endl;
    return 0;
}
