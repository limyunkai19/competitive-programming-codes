#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double tape_length(int a){
    a -= 2;
    return pow(2, -(3+2*a)/4.0);
}

int main(){
    int n, require = 2, x;
    double tape = 0;
    cin >> n;
    for(int a = 2; a <= n && require > 0; a++){
        tape += (require/2)*tape_length(a);
        cin >> x;
        require -= x;
        require *= 2;
    }
    if(require > 0){
        cout << "impossible" << endl;
    }
    else{
        printf("%0.7llf\n", tape);
    }
}

