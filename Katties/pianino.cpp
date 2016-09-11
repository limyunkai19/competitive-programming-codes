#include <iostream>
#include <map>
using namespace std;

int k_factor[1000010], a[1000010];
map<int, int> k;

int main() {
    int n, first;
    cin >> n >> first;

    int max_k = 0, max_ans = 0, zero_ans = 1;

    for(int i = 1; i < n; i++){
        cin >> a[i];

        a[i] -= first;
        if(a[i] > a[i-1])
            k_factor[i] = k_factor[i-1] + 1;
        else if(a[i] < a[i-1])
            k_factor[i] = k_factor[i-1] - 1;
        else
            k_factor[i] = k_factor[i-1];


        if(k_factor[i] == 0){
            if(a[i] == 0)
                zero_ans++;
        }
        else if(a[i] % k_factor[i] == 0){
            k[a[i]/k_factor[i]] = k[a[i]/k_factor[i]] + 1;
            if(k[a[i]/k_factor[i]] > max_ans){
                max_k = a[i]/k_factor[i];
                max_ans = k[max_k];
            }
        }

    }

    cout << k[max_k] + zero_ans << ' ' << max_k << endl;

    return 0;
}