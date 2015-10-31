#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int n, r, l, u;
map<string, int> index;
string name;
vector<vector<int> > U;
vector<vector<int> > L;
vector<vector<int> > C;

int main()
{
    cin >> n >> r;
    U.assign(n, vector<int>());
    L.assign(n, vector<int>());
    C.assign(n, vector<int>());
    int base[n], D[n], bit[n];
    for(int i = 0; i < n; i++){
        cin >> name;
        index[name] = i;
        cin >> base[i] >> bit[i] >> D[i];
        for(int k = 0; k < D[i]; k++){
            cin >> l >> u;
            L[i].push_back(l);
            U[i].push_back(u);
        }
    }
    int temp;
    for(int i = 0; i < n; i++){
        C[i].push_back(bit[i]);
        for(int k = 1; k <= D[i] - 1; k++){
            temp = C[i][k-1]*(U[i][D[i]-k] - L[i][D[i]-k] + 1);
            C[i].push_back(temp);
        }
        C[i].push_back(base[i]);
        for(int k = 0; k <= D[i] - 1; k++){
            C[i][D[i]] -= C[i][k]*L[i][D[i]-k-1];
        }
    }

    int phyAdd, id;
    for(int i = 0; i < r; i++){
        cin >> name;
        id = index[name];
        phyAdd = C[id][D[id]];
        cout << name << "[";
        for(int k = 0; k < D[id]; k++){
            cin >> temp;
            phyAdd += temp*C[id][D[id]-k-1];
            cout << temp;
            if(k != D[id] - 1){
                cout << ", ";
            }
        }
        cout << "] = " << phyAdd << endl;
    }
    return 0;
}
