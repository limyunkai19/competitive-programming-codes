#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

void p(vector<int> a){
    //cout << "size : " << a.size() << " value: ";
    for(int i = 0; i < a.size(); i++){
        cout << a[i];
    }
    cout << endl << endl;
}

bool is_larger(vector<int> a, vector<int> b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            return (a[i] > b[i]);
        }
    }
    return false;
}

int main()
{
    freopen("out.txt", "w", stdout);
    vector<int> largest(9, 0);
    vector<int> temp;
    int dig_left;
    bool used[10], sol;
    int multi = 1;
    int m, t, q;
    for(int i = 9; i < 10000; i++){
        if(i/multi > 9){
            multi *= 10;
        }
        if(i/multi != 9){
            //continue;
        }
        //cout << i << endl;
        memset(used, false, sizeof used);
        used[0] = true;
        dig_left = 9;
        q = 0;
        sol = true;
        temp.clear();
        for(int a = 1;; a++){
            t = i*a;
            while(t > 0){
                if(!used[t%10]){
                    used[t%10] = true;
                    dig_left--;
                    q *= 10;
                    q += t%10;
                }
                else{
                    sol = false;
                    break;
                }
                t /= 10;
            }
            if(sol == false){
                break;
            }
            while(q > 0){
                temp.push_back(q%10);
                q /= 10;
            }
            if(dig_left == 0){
                break;
            }
        }
        if(sol == true){
            cout << i << endl << endl;
            p(temp);
            if(is_larger(temp, largest)){
                largest = temp;
                //p(largest);
            }
        }

    }

    return 0;
}
