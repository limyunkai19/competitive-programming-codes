#include <iostream>

using namespace std;

int graph[400][400];
int componentSize[400];
bool initial[400];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        cin >> graph[i][j];
    }

    // floyd warshall
    for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        graph[i][j] |= graph[i][k] & graph[k][j];
    }

    for(int i = 0; i < n; i++) {
        componentSize[i] = 0;
        for(int j = 0; j < n; j++) {
            componentSize[i] += graph[i][j];
        }
    }

    int x;
    while(cin >> x) {
        initial[x] = true;
    }

    int ans = -1, maxComponentSize = 0;
    for(int i = 0; i < n; i++) {
        if(initial[i]) {
            bool solo = false;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(graph[i][j] && initial[j]) solo = false;
            }

            if(solo) {
                if(componentSize[i] > maxComponentSize) {
                    maxComponentSize = componentSize[i];
                    ans = i;
                }
            }
        }
    }

    // if there is some component with single initial infected machine
    if(ans != -1) {
        cout << ans << endl;
        return 0;
    }

    // all component have more than 2 initial infected machine, output the smallest index of initial infected machine
    for(int i = 0; i < n; i++) {
        if(initial[i]) {
            cout << i << endl;
            return 0;
        }
    }
}
