#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int r, c, map[1005][1005], n, k, a, b, x_s, y_s, x_e, y_e;

int main()
{

    cin >> r >> c;
    while(r != 0){
        memset(map, -1, sizeof map);
        cin >> n;
        while(n--){
            cin >> a >> k;
            while(k--){
                cin >> b;
                map[a][b] = -2;
            }
        }
        cin >> x_s >> y_s >> x_e >> y_e;
        queue<pair<int, int> > q;
        q.push(pair<int, int>(x_s, y_s));
        map[x_s][y_s] = 0;
        pair<int, int> temp;
        int d_x[4] = {0, 0, 1, -1}, d_y[4] = {1, -1, 0, 0};
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp.first > 0 && map[temp.first-1][temp.second] == -1){
                map[temp.first-1][temp.second] = map[temp.first][temp.second] + 1;
                q.push(make_pair(temp.first-1, temp.second));
            }
            if(temp.first < r-1 && map[temp.first+1][temp.second] == -1){
                map[temp.first+1][temp.second] = map[temp.first][temp.second] + 1;
                q.push(make_pair(temp.first+1, temp.second));
            }
            if(temp.second > 0 && map[temp.first][temp.second-1] == -1){
                map[temp.first][temp.second-1] = map[temp.first][temp.second] + 1;
                q.push(make_pair(temp.first, temp.second-1));
            }
            if(temp.second < c-1 && map[temp.first][temp.second+1] == -1){
                map[temp.first][temp.second+1] = map[temp.first][temp.second] + 1;
                q.push(make_pair(temp.first, temp.second+1));
            }
            /*for(int i = 0; i < 4; i++){
                if(map[temp.first+d_x[i]][temp.second+d_y[i]] == -1){
                    map[temp.first+d_x[i]][temp.second+d_y[i]] = map[temp.first][temp.second] + 1;
                    q.push(pair<int, int>(temp.first+d_x[i], temp.second+d_y[i]));
                }
            }*/
        }
        cout << map[x_e][y_e] << endl;

        cin >> r >> c;
    }

    return 0;
}
