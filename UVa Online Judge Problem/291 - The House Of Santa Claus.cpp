#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

vector<int> sec;
bool visited[10][10];
int counter = 0;

void printsec(){
    for(int i = 0; i < sec.size(); i++){
        cout << sec[i];
    }
    //cout <<  " " << ++counter << endl;
    cout << endl;
}

void find(int s, int n){
    if(n == 0){
        printsec();
        return;
    }
    if(s == 1){
        if(!visited[1][2]){
            visited[1][2] = true;
            sec.push_back(2);
            find(2, n-1);
            visited[1][2] = false;
            sec.pop_back();
        }
        if(!visited[1][3]){
            visited[1][3] = true;
            sec.push_back(3);
            find(3, n-1);
            visited[1][3] = false;
            sec.pop_back();
        }
        if(!visited[1][5]){
            visited[1][5] = true;
            sec.push_back(5);
            find(5, n-1);
            visited[1][5] = false;
            sec.pop_back();
        }
    }
    else if(s == 2){
        if(!visited[1][2]){
            visited[1][2] = true;
            sec.push_back(1);
            find(1, n-1);
            visited[1][2] = false;
            sec.pop_back();
        }
        if(!visited[2][3]){
            visited[2][3] = true;
            sec.push_back(3);
            find(3, n-1);
            visited[2][3] = false;
            sec.pop_back();
        }
        if(!visited[2][5]){
            visited[2][5] = true;
            sec.push_back(5);
            find(5, n-1);
            visited[2][5] = false;
            sec.pop_back();
        }
    }
    else if(s == 3){
        if(!visited[1][3]){
            visited[1][3] = true;
            sec.push_back(1);
            find(1, n-1);
            visited[1][3] = false;
            sec.pop_back();
        }
        if(!visited[2][3]){
            visited[2][3] = true;
            sec.push_back(2);
            find(2, n-1);
            visited[2][3] = false;
            sec.pop_back();
        }
        if(!visited[3][4]){
            visited[3][4] = true;
            sec.push_back(4);
            find(4, n-1);
            visited[3][4] = false;
            sec.pop_back();
        }
        if(!visited[3][5]){
            visited[3][5] = true;
            sec.push_back(5);
            find(5, n-1);
            visited[3][5] = false;
            sec.pop_back();
        }
    }
    else if(s == 4){
        if(!visited[3][4]){
            visited[3][4] = true;
            sec.push_back(3);
            find(3, n-1);
            visited[3][4] = false;
            sec.pop_back();
        }
        if(!visited[4][5]){
            visited[4][5] = true;
            sec.push_back(5);
            find(5, n-1);
            visited[4][5] = false;
            sec.pop_back();
        }
    }
    else if(s == 5){
        if(!visited[1][5]){
            visited[1][5] = true;
            sec.push_back(1);
            find(1, n-1);
            visited[1][5] = false;
            sec.pop_back();
        }
        if(!visited[2][5]){
            visited[2][5] = true;
            sec.push_back(2);
            find(2, n-1);
            visited[2][5] = false;
            sec.pop_back();
        }
        if(!visited[3][5]){
            visited[3][5] = true;
            sec.push_back(3);
            find(3, n-1);
            visited[3][5] = false;
            sec.pop_back();
        }
        if(!visited[4][5]){
            visited[4][5] = true;
            sec.push_back(4);
            find(4, n-1);
            visited[4][5] = false;
            sec.pop_back();
        }
    }

}

int main()
{
    memset(visited, false, sizeof visited);
    sec.push_back(1);
    find(1, 8);

    return 0;
}
