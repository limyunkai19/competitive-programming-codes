#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[110], cluster;
vector<int> p;

void init(int n){
    p.resize(n);
    cluster = n;
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
}

int find_set(int x){
    if(p[x] == x) return x;
    return p[x] = find_set(p[x]);
}

void merge_set(int x, int y){
    int px = find_set(x), py = find_set(y);
    if(px != py){
        cluster--;
        p[px] = py;
    }
}

int diff(int x, int y){
    if(x > y) return x-y;
    return y-x;
}

int main(){
    int t, n, k;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n >> k;
        init(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int j = 0; j < i; j++){
                if(diff(a[i], a[j]) <= k)
                    merge_set(i, j);
            }
        }
        cout << "Case #" << tc << ": " << cluster << endl;
    }

    return 0;
}