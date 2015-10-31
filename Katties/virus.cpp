#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int i;
    for(i = 0; i < b.size() && i < a.size(); i++){
        if(a[i] != b[i])
            break;
    }
    int j, k;
    for(j = a.size()-1, k = b.size()-1; j >= 0 && k >= 0; j--, k--){
        if(a[j] != b[k])
            break;
    }
    if(i > k || i > j){
        if(a.size() > b.size()){
            cout << 0 << endl;
        }
        else{
            cout << b.size()-a.size() << endl;
        }
    }
    else{
        cout << b.size()-(i)-(b.size()-k-1) << endl;
    }

    return 0;
}