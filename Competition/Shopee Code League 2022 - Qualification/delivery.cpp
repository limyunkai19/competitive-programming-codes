#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int main() {
    int r, c;
    cin >> r >> c;

    unordered_map<int, vector<pair<int, int>>> portalIdx;
    vector<vector<int>> portal(r+2, vector<int>(c+2, -1));
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> portal[i][j];
            if(portal[i][j] != 0) {
                portalIdx[portal[i][j]].emplace_back(i, j);
            }
        }
    }

    constexpr int INF = 1<<30;
    queue<pair<int, int>> q;
    vector<vector<int>> dist(r+2, vector<int>(c+2, INF));

    if(portal[1][1] != 0) {
        for(auto& [pr, pc] : portalIdx[portal[1][1]]) {
            dist[pr][pc] = 0;
            q.emplace(pr, pc);
        }
    }
    else {
        dist[1][1] = 0;
        q.emplace(1, 1);
    }

    while(!q.empty()) {
        auto [ur, uc] = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int vr = ur + dr[i];
            int vc = uc + dc[i];

            if(portal[vr][vc] == -1 || dist[vr][vc] != INF)
                continue;

            dist[vr][vc] = dist[ur][uc] + 1;
            q.emplace(vr, vc);
            if(portal[vr][vc] != 0) {
                for(auto& [pr, pc] : portalIdx[portal[vr][vc]]) {
                    if(dist[pr][pc] != INF) continue;

                    dist[pr][pc] = dist[vr][vc];
                    q.emplace(pr, pc);
                }
            }
        }
    }

    cout << dist[r][c] << endl;

    return 0;
}
