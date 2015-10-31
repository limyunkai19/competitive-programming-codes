#include <iostream>
#include <cstdio>

using namespace std;

//1 turn is 360/40 = 9 deg

int main(){
    int a, b, c, d, turn;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while(a+b+c+d != 0){
        turn = 40*3;
        if(a > b){
            turn += a - b;
        }
        else {
            turn += a + 40 - b;
        }
        /*if(b >= a){
            turn += b - a;
        }
        else{
            turn += b + 40 - a;
        }
        if(b >= c){
            turn += b - c;
        }
        else{
            turn += b + 40 -c;
        }
        if(d > c){
            turn += d-c;
        }
        else{
            turn += d+40-c;
        }*/
        if(b < c){
            turn += c - b;
        }
        else{
            turn += c - b + 40;
        }
        if(d < c){
            turn += c - d;
        }
        else{
            turn += c + 40 - d;
        }
        printf("%d\n", turn*9);




        scanf("%d %d %d %d", &a, &b, &c, &d);
    }

	return 0;
}
