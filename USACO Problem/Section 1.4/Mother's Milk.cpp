#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool visited[21][21][21];

int A, B, C;

void pour(int a, int b, int c){
    if(visited[a][b][c]){return;}
    visited[a][b][c] = true;
    if(a != 0){
        //a -> b
        if(b < B){
            if(B - b >= a){
                pour(0, b + a, c);
            }
            else{
                pour(a - B+b, B, c);
            }
        }
        //a -> c
        if(c < C){
            if(C - c >= a){
                pour(0, b, c+a);
            }
            else{
                pour(a - C+c, b, C);
            }
        }
    }
    if(b != 0){
        //b -> a
        if(a < A){
            if(A - a >= b){
                pour(a + b, 0, c);
            }
            else{
                pour(A, b - A+a, c);
            }
        }
        //b -> c
        if(c < C){
            if(C - c >= b){
                pour(a, 0, c + b);
            }
            else{
                pour(a, b - C+c, C);
            }
        }
    }
    if(c != 0){
        //c -> a
        if(a < A){
            if(A - a >= c){
                pour(a + c, b, 0);
            }
            else{
                pour(A, b, c - A+a);
            }
        }
        //c -> b
        if(b < B){
            if(B - b >= c){
                pour(a, b + c, 0);
            }
            else{
                pour(a, B, c - B+b);
            }
        }
    }
}

int main()
{
    memset(visited, false, sizeof visited);
    cin >> A >> B >> C;
    pour(0, 0, C);
    for(int i = 0; i < C; i++){
        if(visited[0][C-i][i]){
            cout << i << " ";
        }
    }
    cout << C << endl;


    return 0;
}
