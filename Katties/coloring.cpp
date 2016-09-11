#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int color[20], min_color = 10000, n;
vector<vector<int> > graph;

void coloring(int u, int color_num){
    // prune
    if(color_num >= min_color){
        return;
    }

    // all colored
    if(u == n){
        min_color = min(color_num, min_color);
        return;
    }


    // color u with a color and dont violate rule
    for(int i = 1; i <= color_num+1; i++){
        bool can_color = true;
        for(int j = 0; j < graph[u].size(); j++){
            int v = graph[u][j];
            if(color[v] == i){
                can_color = false;
                break;
            }
        }

        if(can_color){
            // try color with i
            color[u] = i;
            coloring(u+1, max(color_num, i));
            // backtrack
            color[u] = 0;
        }
    }

}

int main(){
    cin >> n;
    graph.assign(n, vector<int> ());
    string x;
    getline(cin, x);
    for(int i = 0; i < n; i++){
        getline(cin, x);
        stringstream ss(x);

        int v;
        while(ss >> v){
            graph[i].push_back(v);
        }
    }

    coloring(0, 0);

    cout << min_color << endl;

    return 0;
}