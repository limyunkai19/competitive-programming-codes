#include <iostream>

using namespace std;

int parent[5010], a[510];
bool set[510];
int main(){
    int l, n;
    cin >> l >> n;
    parent[0] = -1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = l; j >= 0; j--){
                            // u dont want to overwrite v this, to avoid the parent is u
            if(parent[j] != 0 && j+a[i] <= l && parent[j+a[i]] == 0){
                parent[j+a[i]] = i;
            }
        }
    }

    int largest = l;
    while(parent[largest] == 0)
        largest--;

    while(parent[largest] != -1){
        set[parent[largest]] = 1;
        largest -= a[parent[largest]];
    }

    int set0 = 0, set1 = 0;
    for(int i = 1; i <= n; i++){
        if(set[i] == 0){
            cout << set0 << ' ';
            set0 += a[i];
        }
        else{
            cout << set1 << ' ';
            set1 += a[i];
        }
    }
    cout << endl;


    return 0;
}