#include <iostream>
#include <vector>

using namespace std;

void connect(int l, int r, vector<bool>& connected, const vector<int>& next) {
    if(l >= r) return;

    if(connected[l]) {
        connect(l+1, r, connected, next);
        return;
    }

    // try connect l and counter[l]
    if(l < next[l] && next[l] <= r) {
        // can connect
        connected[l] = connected[next[l]] = true;
        connect(l+1, next[l]-1, connected, next);
        connect(next[l]+1, r, connected, next);

        return;
    }

    // cannot then try next one
    connect(l+1, r, connected, next);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(2*n), visit(n, -1), next(2*n);
        for(int i = 0; i < a.size(); i++) {
            cin >> a[i]; a[i]--;
            if(visit[a[i]] == -1) {
                visit[a[i]] = i;
            }
            else {
                next[i] = visit[a[i]];
                next[visit[a[i]]] = i;
            }
        }

        vector<bool> connected(2*n, false);
        // connect outer
        connect(0, 2*n-1, connected, next);
        // then connect inner
        connect(0, 2*n-1, connected, next);

        bool success = true;
        for(int i = 0; i < 2*n; i++) {
            if(!connected[i]) {
                success = false;
            }
        }

        if(success)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
