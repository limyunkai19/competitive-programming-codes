/*
ID: yunkai91
LANG: C++
TASK: spin
*/

#include <iostream>
#include <cstdio>

using namespace std;

bool space[5][360];
int pos[5], turn[5];

int main(){
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);

    int k, a, b;
    for(int wheel = 0; wheel < 5; wheel++){
        cin >> turn[wheel];
        cin >> k;
        while(k--){
            cin >> a >> b;
            for(int i = 0; i <= b; i++){
                space[wheel][(a+i)%360] = true;
            }
        }
    }
    bool light[360];
    for(int sec = 0; sec < 360; sec++){
        // using this pos;
        for(int i = 0; i < 360; i++) light[i] = true;
        for(int wheel = 0; wheel < 5; wheel++){
            for(int i = 0; i < 360; i++){
                light[(i+pos[wheel])%360] &= space[wheel][i];
            }
            //update pos
            pos[wheel] += turn[wheel];
        }

        for(int i = 0; i < 360; i++){
            if(light[i]){
                cout << sec << endl;
                return 0;
            }
        }
    }

    cout << "none" << endl;


    return 0;
}