#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int map[110][110], area[100010];
int tc, r, c, colour;

void dfs(int r, int c){
    area[colour]++;
    map[r][c] = colour;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(map[r+i][c+j] == 1){
                dfs(r+i, c+j);
            }
        }
    }
}

int main()
{
    //freopen("inout.txt", "r", stdin);
    string a;

    cin >> tc;
    while(tc--){
        cin >> a;
        c = a.size();
        r = 0;
        memset(map, 0, sizeof map);
        memset(area, 0, sizeof area);
        while(isalpha(a.at(0))){
            r++;
            for(int i = 0 ; i < c; i++){
                if(a.at(i) == 'W'){
                    map[r][i+1] = 1;
                }
                //cout << map[r][i+1];
            }
            //cout << endl;
            cin >> a;
        }
        colour = 2;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                if(map[i][j] == 1){
                    dfs(i, j);
                    colour++;
                }
            }
        }
        /*for(int i = 0; i < r; i++){
            for(int j = 1; j < c; j++){
                cout << map[i+1][j+1];
            }
            cout << endl;
        }*/
        stringstream ss(a);
        ss >> r; cin >> c; getchar();
        cout << area[map[r][c]] << endl;
        if(tc){
            getline(cin, a);
            while(a.size() > 0){
                stringstream ss(a);
                ss >> r >> c;
                cout << area[map[r][c]] << endl;
                getline(cin, a);
                //cout << "infloop" << endl;
            }
            cout << "\n";
        }
        else{
            while(cin >> r >> c){
                cout << area[map[r][c]] << endl;
                //cout << "infloop?" << endl;
            }
        }
        //else
        //getline(cin, a);
        /*while(getchar() != "\n"){
            //stringstream ss(a);
            cin >> r >> c;
            cout << area[map[r][c]] << endl;
            //getline(cin, a);
            //cout << "1 " << a << endl;

        }*/
    }
    return 0;
}
