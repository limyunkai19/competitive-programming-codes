#include <iostream>

using namespace std;

long long a[10100], b[10100];
long long sum = 0;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(n%3 == 1){
        b[0] = sum/3;
        b[1] = sum/3;
        for(int i = 2; i < n; i+=3){
            b[0] -= a[i];
            b[1] -= a[i+1];
        }
        for(int i = 2; i < n; i++){
            b[i] = a[i-1]-b[i-1]-b[i-2];
        }
    }
    else if(n%3 == 2){
        b[0] = sum/3-a[n-1];
        b[1] = sum/3-a[0];
        for(int i = 1; i < n-1; i+=3){
            b[0] -= a[i];
            b[1] -= a[i+1];
        }
        b[0] = -b[0];
        b[1] = -b[1];
        for(int i = 2; i < n; i++){
            b[i] = a[i-1]-b[i-1]-b[i-2];
        }
    }
    else{
        long long lowest[3] = {1, 1, 1};
        b[0] = b[1] = b[2] = 1;
        for(int i = 3; i < n; i ++){
            b[i] = a[i-1] - a[i-2] + b[i-3];
            lowest[i%3] = min(lowest[i%3], b[i]);
        }
        long long cur_sum = 0;
        for(int i = 0; i < n; i++){
            b[i] += 1-lowest[i%3];
            cur_sum += b[i];
        }

        int diff = (sum-cur_sum*3)/(long long)n;
        for(int i = 0; i < n; i+= 3)
            b[i] += diff;
    }


    for(int i = 0; i < n; i++){
        cout << b[i] << endl;
    }

    return 0;
}
