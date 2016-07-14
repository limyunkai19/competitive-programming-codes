#include <iostream>

using namespace std;

string names[210];

int main(){
    int n;
    string delim = "";
    while(cin >> n && n != 0){

        for(int i = 0; i < n; i++){
            cin >> names[i];
            for(int j = i; j >= 1; j--){
                if(names[j][0] < names[j-1][0] || names[j][0] == names[j-1][0] && names[j][1] < names[j-1][1]){
                    swap(names[j], names[j-1]);
                }
                else{
                    break;
                }
            }
        }

        cout << delim;
        delim = "\n";
        for(int i = 0; i < n; i++){
            cout << names[i] << endl;
        }
    }

    return 0;
}