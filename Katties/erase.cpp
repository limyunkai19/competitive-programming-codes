#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    bool del = true;
    for(int i = 0; i < a.size(); i++){
        if(n%2 == 0 && a[i] != b[i]){
            del = false;
        }
        if(n%2 == 1 && a[i] == b[i]){
            del = false;
        }
    }
    if(del)
        cout << "Deletion succeeded" << endl;
    else
        cout << "Deletion failed" << endl;

    return 0;
}