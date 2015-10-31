#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int a, mini;
    string road;
    char last;
    int last_idx;
    //freopen("data.txt", "r", stdin);
    while(cin >> a){
        if(a == 0) break;
        cin >> road;
        mini = road.size() + 3;
        last = '.';
        for(int i = 0; i < road.size(); i++){
            if(road[i] == 'Z'){
                mini = 0;
                break;
            }
            else if(road[i] == last && road[i] != '.'){
                last_idx = i;
            }
            else if(road[i] != last && road[i] != '.'){
                //cout << last << endl;
                if(last == '.'){
                    last = road[i];
                    last_idx = i;
                }
                else{
                    last = road[i];
                    mini = min(i-last_idx, mini);
                    last_idx = i;
                }
            }
        }
        cout << mini << endl;
    }

	return 0;
}
