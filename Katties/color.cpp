#include <iostream>
#include <algorithm>

using namespace std;

int a[100100];

int main(){
    int n, c, k;
    cin >> n >> c >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    int ans = 1, smallest = a[0], used = 1;
    for(int i = 1; i < n; i++){
        if(used == c || a[i] - smallest > k){
            used = 1;
            ans++;
            smallest = a[i];
        }
        else{
            used++;
        }
    }

    cout << ans << endl;

    return 0;
}