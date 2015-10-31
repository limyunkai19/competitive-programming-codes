/*
ID: yunkai91
LANG: C++
TASK: maze1
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int dist[300][300];
vector<string> maze;

int main(){
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

    memset(dist, -1, sizeof dist);

    int w, h;
    cin >> w >> h;

    queue<ii> q;
    string x;
    cin.ignore();
    //cin.ignore();
    for(int i = 0; i < 2*h+1; i++){
        getline(cin, x);
        maze.push_back(x);
    }
    for(int i = 0; i < maze.size(); i++){
        if(maze[i][0] == ' '){
            q.push(ii(i, 1));
            dist[i][1] = 1;
            maze[i][0] = '.';
        }
        if(maze[i][maze[i].size()-1] == ' '){
            q.push(ii(i, maze[i].size()-2));
            dist[i][maze[i].size()-2] = 1;
            maze[i][maze[i].size()-1] = '.';
        }
    }
    for(int i = 0; i < maze[0].size(); i++){
        if(maze[0][i] == ' '){
            q.push(ii(1, i));
            dist[1][i] = 1;
            maze[0][i] = '.';
        }
        if(maze[maze.size()-1][i] == ' '){
            q.push(ii(maze.size()-2, i));
            dist[maze.size()-2][i] = 1;
            maze[maze.size()-1][i] = '.';
        }
    }
    //cout << q.size() << endl;
    int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
    int maxdist = 1;
    while(!q.empty()){
        int ui = q.front().first, uj = q.front().second;
        //cout << ui << ' ' << uj << endl;
        q.pop();
        for(int i = 0; i < 4; i++){
            int fencei = ui+di[i], fencej = uj+dj[i], vi = ui+2*di[i], vj = uj+2*dj[i];
            if(maze[fencei][fencej] == ' ' && dist[vi][vj] == -1){
                q.push(ii(vi, vj));
                dist[vi][vj] = dist[ui][uj] + 1;
                maxdist = max(dist[vi][vj], maxdist);
            }
        }
    }
    cout << maxdist << endl;

    return 0;
}