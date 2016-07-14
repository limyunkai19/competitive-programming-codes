#include <iostream>
#include <cstring>

using namespace std;

#define LIMIT 25010

int fun[LIMIT+10];

int main(){
    int n;
    cin >> n;

    while(n--){
        int a, b, t;
        cin >> a >> b >> t;

        if(b == 0){
            // special case, b = 0
            // if handle using below technique yield O(LIMIT^2)
            for(int i = 0; i+t <= LIMIT; i++){
                if(fun[i+t] < fun[i]+a){
                    fun[i+t] = fun[i]+a;
                }
            }
        }
        else{
            // sqrt(1000) ~= 31, thus the loop is 31 * O(LIMIT)
            // observation, each roller coaster is independent to each other
            // thus below dp relation hold
            // cannot use the above 1 pass method as each ride is dependent to each other
            for(int i = LIMIT-t; i >= 0; i--){
                int fun_val = 0;
                for(int ride = 0; a-ride*ride*b > 0 && i + (ride+1)*t <= LIMIT; ride++){
                    fun_val += a-ride*ride*b;
                    if(fun[i+(ride+1)*t] < fun[i]+fun_val){
                        fun[i+(ride+1)*t] = fun[i]+fun_val;
                    }
                }
            }
        }

    }

    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << fun[x] << endl;
    }



    return 0;
}