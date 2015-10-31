#include <iostream>

using namespace std;

unsigned long long int triangle(int i){
    return i*(i+1)/2;
}

unsigned long long int divisor(int i){
    int divisorOfk = 0, divisorOfi = 0;
    if(i%2 == 0){
        int k = i/2;
        for(int a = 1; a <= k; a++){
            if(k%a == 0){
                divisorOfk++;
            }
        }
        for(int b = 1; b <= i+1; b++){
            if((i+1)%b == 0){
                divisorOfi++;
            }
        }
    }
    else{
        int k = (i+1)/2;
        for(int a = 1; a <= k; a++){
            if(k%a == 0){
                divisorOfk++;
            }
        }
        for(int b = 1; b <= i; b++){
            if(i%b == 0){
                divisorOfi++;
            }
        }
    }
    return divisorOfk*divisorOfi;
}

int main(){
    int n=1;
    while(divisor(n) < 500){
        n++;
    }
    cout << triangle(n) << endl;
    return 0;
}
