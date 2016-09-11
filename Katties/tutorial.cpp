#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    long long limit, n, type;
    cin >> limit >> n >> type;
    if(type == 3){
        int now = 1;
        for(int i = 0; i < 4; i++){
            now *= n;
            if(now > limit){
                cout << "TLE" << endl;
                return 0;
            }
        }
        cout << "AC" << endl;
        return 0;
    }
    if(type == 4){
        int now = 1;
        for(int i = 0; i < 3; i++){
            now *= n;
            if(now > limit){
                cout << "TLE" << endl;
                return 0;
            }
        }
        cout << "AC" << endl;
        return 0;
    }
    if(type == 5){
        int now = 1;
        for(int i = 0; i < 2; i++){
            now *= n;
            if(now > limit){
                cout << "TLE" << endl;
                return 0;
            }
        }
        cout << "AC" << endl;
        return 0;
    }
    if(type == 7){
        if(n > limit)
            cout << "TLE" << endl;
        else
            cout << "AC" << endl;
        return 0;
    }
    if(type == 1){
        int now = 1;
        for(int i = 1; i <= n; i++){
            now *= i;
            if(now > limit){
                cout << "TLE" << endl;
                return 0;
            }
        }
        cout << "AC" << endl;
        return 0;
    }
    if(type == 2){
        int now = 1;
        for(int i = 1; i <= n; i++){
            now *= 2;
            if(now > limit){
                cout << "TLE" << endl;
                return 0;
            }
        }
        cout << "AC" << endl;
        return 0;
    }
    if(type == 6){
        double dlimit = limit;
        double now = n;
        now *= log2(n);
        if(now > limit){
            cout << "TLE" << endl;
        }
        else
            cout << "AC" << endl;
    }


    return 0;
}