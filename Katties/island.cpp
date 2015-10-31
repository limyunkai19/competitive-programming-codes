#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<string> graph;

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

bool fill(int x, int y, char detect1, char detect2, char fillchar){
    graph[x][y] = fillchar;
    bool run = false;
    for(int i = 0; i < 4; i++){
        if(x+dx[i] < 0 || x+dx[i] >= graph.size() ||
           y+dy[i] < 0 || y+dy[i] >= graph[0].size())  continue;
        else{
            if(graph[x+dx[i]][y+dy[i]] == detect1 || graph[x+dx[i]][y+dy[i]] == detect2){
                fill(x+dx[i], y+dy[i], detect1, detect2, fillchar);
                run = true;
            }
        }
    }
    return run;
}

int main(){
    string line;
    int map = 1;
    while(1){
        bool input = getline(cin, line);
        if(line.size() == 0 || !input){
            //run
            int bridge = 0, island = 0, bus = 0;
            for(int i = 0; i < graph.size(); i++){
                for(int j = 0; j < graph[i].size(); j++){
                    if(graph[i][j] == 'X' || graph[i][j] == '#'){
                        fill(i, j, '#', 'X', 'i');
                        island++;
                    }
                    if(graph[i][j] == 'B'){
                        fill(i, j, 'B', 'B', 'b');
                        bridge++;
                    }
                }
            }
            for(int i = 0; i < graph.size(); i++){
                for(int j = 0; j < graph[i].size(); j++){
                    cout << graph[i][j];
                }
                cout << endl;
            }
            for(int i = 0; i < graph.size(); i++){
                for(int j = 0; j < graph[i].size(); j++){
                    if(graph[i][j] == 'i'){
                        fill(i, j, 'b', 'i', '.');
                        bus++;
                    }
                }
            }
            if(map != 1) cout << endl;
            cout << "Map " << map << endl;
            cout << "islands: " << island << endl;
            cout << "bridges: " << bridge << endl;
            cout << "buses needed: " << bus << endl;

            //reset
            graph.clear();
            map++;
            if(!input) return 0;
        }
        else{
            graph.push_back(line);
        }

    }

    return 0;
}