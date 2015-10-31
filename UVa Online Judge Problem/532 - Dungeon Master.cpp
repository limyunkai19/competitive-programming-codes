#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define _x first;
#define _y second.first;
#define _z second.second;

int x, y, z, a, b, c;
char map[35][35][35];
int dist[35][35][35];
int x_s, y_s, z_s, x_e, y_e, z_e;
char temp;
int d_x[6] = {-1, 1, 0, 0, 0, 0};
int d_y[6] = {0, 0, -1, 1, 0, 0};
int d_z[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    cin >> x >> y >> z;
    while(x != 0){
        memset(map, '#', sizeof map);
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= y; j++){
                for(int k = 1; k <= z; k++){
                    cin >> temp;
                    if(temp == 'S'){
                        x_s = i; y_s = j; z_s = k;
                        map[i][j][k] = '.';
                    }
                    else if(temp == 'E'){
                        x_e = i; y_e = j; z_e = k;
                        map[i][j][k] = '.';
                    }
                    else{
                        map[i][j][k] = temp;
                    }
                }
            }
        }
        /*for(int i = 0; i <= x+1; i++){
            for(int j = 0; j <= y+1; j++){
                for(int k = 0; k <= z+1; k++){
                    printf("%c", map[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }*/
        memset(dist, -1, sizeof dist);
        queue<iii> q;
        //printf("%d %d %d\n", x_e, y_e, z_e);
        q.push(iii(x_s, ii(y_s, z_s)));
        dist[x_s][y_s][z_s] = 0;
        while(!q.empty()){
            a = q.front()._x; b = q.front()._y; c = q.front()._z;
            //printf("%d %d %d\n", a, b, c);
            q.pop();
            for(int i = 0; i < 6; i++){
                if(dist[a+d_x[i]][b+d_y[i]][c+d_z[i]] == -1 && map[a+d_x[i]][b+d_y[i]][c+d_z[i]] == '.'){
                    dist[a+d_x[i]][b+d_y[i]][c+d_z[i]] = dist[a][b][c] + 1;
                    //printf("%d %d %d = %d\n", a+d_x[i], b+d_y[i], c+d_z[i], dist[a+d_x[i]][b+d_y[i]][c+d_z[i]]);
                    q.push(iii(a+d_x[i], ii(b+d_y[i], c+d_z[i])));
                }
            }
        }
        /*for(int i = 0; i <= x+1; i++){
            for(int j = 0; j <= y+1; j++){
                for(int k = 0; k <= z+1; k++){
                    printf("%d", dist[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }*/
        if(dist[x_e][y_e][z_e] > 0){
            printf("Escaped in %d minute(s).\n", dist[x_e][y_e][z_e]);
        }
        else{
            printf("Trapped!\n");
        }
        cin >> x >> y >> z;
    }

    return 0;
}
