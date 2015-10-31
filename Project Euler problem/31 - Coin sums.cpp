#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    int way = 0;
    for(int a = 0; a <= 1; a++){
        if(200*a == 200){
            way++;
            break;
        }
        for(int b = 0; b <= 2; b++){
            if(200*a + 100*b > 200){
                break;
            }
            else if(200*a + 100*b == 200){
                way++;
                break;
            }
            for(int c = 0; c <= 4; c++){
                if(200*a + 100*b + 50*c > 200){
                    break;
                }
                else if(200*a + 100*b + 50*c == 200){
                    way++;
                    break;
                }
                for(int d = 0; d <= 10; d++){
                    if(200*a + 100*b + 50*c + 20*d > 200){
                        break;
                    }
                    else if(200*a + 100*b + 50*c + 20*d == 200){
                        way++;
                        break;
                    }
                    for(int e = 0; e <= 20; e++){
                        if(200*a + 100*b + 50*c + 20*d + 10*e > 200){
                            break;
                        }
                        else if(200*a + 100*b + 50*c + 20*d + 10*e == 200){
                            way++;
                            break;
                        }
                        for(int f = 0; f <= 40; f++){
                            if(200*a + 100*b + 50*c + 20*d + 10*e + 5*f > 200){
                                break;
                            }
                            else if(200*a + 100*b + 50*c + 20*d + 10*e + 5*f == 200){
                                way++;
                                break;
                            }
                            for(int g = 0; g <= 100; g++){
                                if(200*a + 100*b + 50*c + 20*d + 10*e + 5*f + 2*g > 200){
                                    break;
                                }
                                else{
                                    way++;
                                    //printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, 200 - (200*a + 100*b + 50*c + 20*d + 10*e + 5*f + 2*g));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << way << endl;
    return 0;
}
