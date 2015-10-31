#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    string board[8];
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }
    bool valid = true;
    int queen = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == '*'){
                queen++;
                for(int k = i+1; k < 8; k++) if(board[k][j] == '*') valid = false;
                for(int k = i-1; k >= 0; k--) if(board[k][j] == '*') valid = false;
                for(int k = j+1; k < 8; k++) if(board[i][k] == '*') valid = false;
                for(int k = j-1; k >= 0; k--) if(board[i][k] == '*') valid = false;

                for(int k = i+1, l = j+1; k < 8 && l < 8; k++, l++) if(board[k][l] == '*') valid = false;
                for(int k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--) if(board[k][l] == '*') valid = false;
                for(int k = i+1, l = j-1; k < 8 && l >= 0; k++, l--) if(board[k][l] == '*') valid = false;
                for(int k = i-1, l = j+1; k >= 0 && l < 8; k--, l++) if(board[k][l] == '*') valid = false;
            }
        }
    }

    if(valid && queen == 8)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    return 0;
}