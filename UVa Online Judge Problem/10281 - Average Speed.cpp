#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string time;
    char temp;
    int hours, min, sec, factor;
    double distance = 0, speed, startmin = 0, nowmin;
    while(getline(cin, time)){
        //getchar();
        if(time.size() > 9){
            hours = 10*(time.at(0) - '0') + (time.at(1) - '0');
            min = 10*(time.at(3) - '0') + (time.at(4) - '0');
            sec = 10*(time.at(6) - '0') + (time.at(7) - '0');
            nowmin = (double)(hours*60.0 + min*1.0 + sec/60.0);
            if(startmin != 0){
                distance += speed*(nowmin- startmin);
            }
            speed = 0;
            factor = 1;
            for(int i = time.size()-1; i > 8; i--){
                //cout << time.at(i) - '0' << endl;
                speed += factor*(time.at(i) - '0');
                factor *= 10;
            }
            speed /= 60;
            startmin = nowmin;
            //cout << hours << " " << min << " " << sec << " " << speed << endl;
            //printf("%0.20lf %0.20lf\n", startmin, speed);
        }
        else{
            hours = 10*(time.at(0) - '0') + (time.at(1) - '0');
            min = 10*(time.at(3) - '0') + (time.at(4) - '0');
            sec = 10*(time.at(6) - '0') + (time.at(7) - '0');
            nowmin = (double)(hours*60.0 + min*1.0 + sec/60.0);
            distance += speed*(nowmin - startmin);
            printf("%.2d:%.2d:%.2d %0.2f km\n", hours, min , sec, distance);
            startmin = nowmin;
        }
    }

    return 0;
}
