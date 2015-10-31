#include <iostream>
#include <cstdio>

using namespace std;

int a[1000100], tmp[1000100];

long long mergesort(int l, int r){
    if(l == r) return 0;
    if(r == l+1){
        if(a[l] > a[r]){
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
            return 1;
        }
        return 0;
    }
    int mid = (l+r)/2;
    long long ans = mergesort(l, mid)+mergesort(mid+1, r);
    int lsize = mid-l+1, rsize = r-mid, lidx = l, ridx = mid+1;
    for(int i = l; i <= r; i++){
        if(lsize == 0){
            tmp[i] = a[ridx];
            ridx++;
            rsize--;
        }
        else if(rsize == 0){
            tmp[i] = a[lidx];
            lidx++;
            lsize--;
        }
        else if(a[lidx] <= a[ridx]){
            tmp[i] = a[lidx];
            lidx++;
            lsize--;
        }
        else{
            tmp[i] = a[ridx];
            ridx++;
            rsize--;
            ans += lsize;
        }
    }
    for(int i = l; i <= r; i++){
        a[i] = tmp[i];
    }
    return ans;
}

int main(){
    int n;
    ios::sync_with_stdio(false);
    //cin >> n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
    }
    cout << mergesort(0, n-1) << endl;

    return 0;
}