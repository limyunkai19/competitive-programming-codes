#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int tc, a, b;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &a, &b);
        a -= 2; b -= 2;
        if(a % 3 == 0){
            a /= 3;
        }
        else{
            a /= 3;
            a++;
        }
        if(b % 3 == 0){
            b /= 3;
        }
        else{
            b /= 3;
            b++;
        }
        printf("%d\n", a*b);
    }

	return 0;
}
