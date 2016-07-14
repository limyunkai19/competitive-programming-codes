#include <iostream>

using namespace std;

string graph[2000];
int id[1010][1010];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

void fill(int i, int j, int num){
    id[i][j] = num;

    for(int k = 0; k < 4; k++){
        if(id[ i+dy[k] ][ j+dx[k] ] == 0 && graph[ i+dy[k]-1 ][ j+dx[k]-1 ] == graph[ i-1 ][ j-1 ])
            fill(i+dy[k], j+dx[k], num);
    }

}

int main(){
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> graph[i];
    }

    for(int i = 0; i < r+1; i++)
        id[i][0] = id[i][c+1] = -1;
    for(int i = 0; i < c+1; i++)
        id[0][i] = id[r+1][i] = -1;

    int num = 1;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            if(id[i][j] == 0) fill(i, j, num++);


    int q;
    cin >> q;
    while(q--){
        int r1, c1, r2, c2;
        cin >> r1 >>  c1 >>  r2 >>  c2;
        if(id[r1][c1] != id[r2][c2])
            cout << "neither" << endl;
        else if(graph[r1-1][c1-1] == '1')
            cout << "decimal" << endl;
        else
            cout << "binary" << endl;

    }


    return 0;
}