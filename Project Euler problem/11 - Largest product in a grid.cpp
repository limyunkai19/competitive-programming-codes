#include <iostream>
#include <cstdio>

using namespace std;

int grid[25][25];

int row_col(){
    int max_row = 0, row;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 17; j++){
            row = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
            if(row > max_row){
                max_row = row;
            }
        }
    }

    int max_col = 0, col;
    for(int i = 0; i < 17; i++){
        for(int j = 0; j < 20; j++){
            col = grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
            if(col > max_col){
                max_col = col;
            }
        }
    }

    return max(max_row, max_col);
}

int dia(){
    int max_pos = 0, pos;
    for(int i = 19; i >= 3; i--){
        for(int j = 0; j < 17; j++){
            pos = grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3];
            if(pos > max_pos){
                max_pos = pos;
            }
        }
    }

    int max_neg = 0, neg;
    for(int i = 0; i < 17; i++){
        for(int j = 0; j < 17; j++){
            neg = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
            if(neg > max_neg){
                max_neg = neg;
            }
        }
    }

    return max(max_pos, max_neg);
}

int main()
{
    freopen("20x20 grid.txt", "r", stdin);
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            cin >> grid[i][j];
        }
    }
    cout << max(dia(), row_col()) << endl;
    return 0;
}
