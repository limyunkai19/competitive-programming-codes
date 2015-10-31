#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct points{
    double x, y;
} mos[50];

bool findcircle(points a, points b, double r, points &c){
    double d2 = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    double det = r*r/d2 - 0.25;
    if(det < 0.0) return false;
    double h = sqrt(det);
    c.x = (a.x+b.x)*0.5 + (a.y-b.y)*h;
    c.y = (a.y+b.y)*0.5 + (b.x-a.x)*h;
    return true;
}

bool insidecircle(points p, points c, double r){
    double d2 = (p.x-c.x)*(p.x-c.x) + (p.y-c.y)*(p.y-c.y);
    if(d2 <= r*r+1e-12){
        return true;
    }
    return false;
}

int main(){
    int tc, n, ans, m;
    double r, x, y;
    cin >> tc;
    while(tc--){
        cin >> n >> r;
        r /= 2;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            mos[i].x = x;
            mos[i].y = y;
        }
        ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                points c;
                if(findcircle(mos[i], mos[j], r, c)){
                    m = 0;
                    for(int k = 0; k < n; k++){
                        if(insidecircle(mos[k], c, r))
                            m++;
                    }
                    ans = max(ans, m);
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}