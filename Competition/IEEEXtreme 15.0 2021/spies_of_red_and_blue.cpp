// link: https://csacademy.com/ieeextreme-practice/task/spies/

#include <iostream>
#include <vector>

using namespace std;

inline int getIdx(const char& team, const int& num, const int& red) {
    if(team == 'R') return num;
    return num + red;
}

int main() {
    constexpr int INF = 1<<30;
    
    int t; cin >> t;
    while(t--) {
        int red, blue, q;
        cin >> red >> blue >> q;
        
        int redLeader = 1, blueLeader = red+1;
        vector<int> parent(red+blue+1);
        for(int i = 2; i <= red; i++) {
            char c; int num;
            cin >> c >> num;
            parent[i] = getIdx(c, num, red);
        }
        for(int i = 2; i <= blue; i++) {
            char c; int num;
            cin >> c >> num;
            parent[i+red] = getIdx(c, num, red);
        }
        
        int visitedColor = 0;
        vector<int> visited(parent.size(), -1);
        while(q--) {
            char e, t1, t2;
            int n1, n2;
            cin >> e >> t1 >> n1 >> t2 >> n2;
            
            if(e == 'c') {
                parent[getIdx(t1, n1, red)] = getIdx(t2, n2, red);
                continue;
            }
            
            auto race = [&](int u, int color) -> pair<char, int> {
                int k = 0;
                while(u != redLeader && u != blueLeader && visited[u] != color) {
                    visited[u] = color;
                    u = parent[u];
                    k++;
                }
                
                if(u == redLeader) 
                    return {'r', k};
                if(u == blueLeader)
                    return {'b', k};
                return {'n', -1};
            };      
            
            auto [r1, k1] = race(getIdx(t1, n1, red), visitedColor++);
            auto [r2, k2] = race(getIdx(t2, n2, red), visitedColor++);
            
            int redStep = INF, blueStep = INF;
            if(r1 == 'r') redStep = min(k1, redStep);
            if(r2 == 'r') redStep = min(k2, redStep);
            if(r1 == 'b') blueStep = min(k1, blueStep);
            if(r2 == 'b') blueStep = min(k2, blueStep);
            
            if(redStep == INF && blueStep == INF) {
                cout <<"NONE\n";
            }
            else if(redStep == blueStep) {
                cout << "TIE " << redStep << '\n';
            }
            else if(redStep < blueStep) {
                cout << "RED " << redStep << '\n';
            }
            else {
                cout << "BLUE " << blueStep << '\n';
            }
        }
    }
    
    return 0;
}

