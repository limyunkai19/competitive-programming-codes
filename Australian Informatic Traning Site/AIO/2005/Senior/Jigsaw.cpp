#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

typedef pair<int, int> ii;
#define y second
#define x first

ii coor[50005];
set<ii> isExist;
int n, mid_x, mid_y;

bool isHorizontal(){
    for(int i = 0; i < n; i++){
        if(isExist.find(ii(abs(mid_x - coor[i].x), coor[i].y)) == isExist.end()){
            return false;
        }
    }
    return true;
}

bool isVertical(){
    for(int i = 0; i < n; i++){
        if(isExist.find(ii(coor[i].x, abs(mid_y - coor[i].y))) == isExist.end()){
            return false;
        }
    }
    return true;
}

bool isP_Diagonal(){
    if((mid_x + mid_y)%2 == 1){
        return false;
    }
    int a, b;
    for(int i = 0; i < n; i++){
        a = mid_x + 2*coor[i].y - mid_y;
        b = mid_y - mid_x + 2*coor[i].x;
        if(isExist.find(ii(a/2, b/2)) == isExist.end()){
            return false;
        }
    }
    return true;
}

bool isN_Diagonal(){
    if((mid_x + mid_y)%2 == 1){
        return false;
    }
    int a, b;
    for(int i = 0; i < n; i++){
        b = mid_y - 2*coor[i].x + mid_x;
        a = mid_x - 2*coor[i].y + mid_y;
        if(isExist.find(ii(a/2, b/2)) == isExist.end()){
            return false;
        }
    }
    return true;
}

bool isRotate(int t){
    if(t%2 == 1 && (mid_x + mid_y)%2 == 1){
        return false;
    }
    int re_x, re_y, pre_x, pre_y;
    for(int i = 0; i < n; i++){
        pre_x = 2*coor[i].x; pre_y = 2*coor[i].y;
        for(int j = 0; j < t; j++){
            re_x = mid_x + pre_y - mid_y;
            re_y = mid_y - pre_x + mid_x;
            pre_x = re_x;
            pre_y = re_y;
        }
        if(isExist.find(ii(pre_x/2, pre_y/2)) == isExist.end()){
            return false;
        }
    }
    return true;
}

void pHorizontal(){
    for(int i = 0; i < n; i++){
        printf("%d %d\n", abs(mid_x - coor[i].x), coor[i].y);
    }
}

void pVertical(){
    for(int i = 0; i < n; i++){
        printf("%d %d\n", coor[i].x, abs(mid_y - coor[i].y));
    }
}

void pRotation(int t){
    int re_x, re_y, pre_x, pre_y;
    for(int i = 0; i < n; i++){
        pre_x = 2*coor[i].x; pre_y = 2*coor[i].y;
        for(int j = 0; j < t; j++){
            re_x = mid_x + pre_y - mid_y;
            re_y = mid_y - pre_x + mid_x;
            pre_x = re_x;
            pre_y = re_y;
        }
        printf("%d %d\n", pre_x/2, pre_y/2);
    }
}

void pP_Diagonal(){
    int a, b;
    for(int i = 0; i < n; i++){
        a = mid_x + 2*coor[i].y - mid_y;
        b = mid_y - mid_x + 2*coor[i].x;
        printf("%d %d\n", a/2, b/2);
    }
}

void pN_Diagonal(){
    int a, b;
    for(int i = 0; i < n; i++){
        b = mid_y - 2*coor[i].x + mid_x;
        a = mid_x - 2*coor[i].y + mid_y;
        printf("%d %d\n", a/2, b/2);
    }
}


int main()
{
    freopen("jigin.txt", "r", stdin);
    freopen("jigout.txt", "w", stdout);
    int up = 1e7, down = -1, left = -1, right = 1e7;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> coor[i].x >> coor[i].y;
        isExist.insert(ii(coor[i].x, coor[i].y));
        up = min(up, coor[i].x);
        down = max(down, coor[i].x);
        left = max(left, coor[i].y);
        right = min(right, coor[i].y);
    }
    int ans = 0;
    bool print[7];
    mid_x = up + down;
    mid_y = left + right;
    ans += print[0] = isHorizontal();
    ans += print[1] = isVertical();
    ans += print[2] = isRotate(1);
    ans += print[3] = isRotate(2);
    ans += print[4] = isRotate(3);
    ans += print[5] = isP_Diagonal();
    ans += print[6] = isN_Diagonal();

    printf("%d\n", ans);
    if(print[0]){pHorizontal(); printf("\n");}
    if(print[1]){pVertical(); printf("\n");}
    for(int i = 2; i <= 4; i++){
        if(print[i]){
            pRotation(i-1);
            printf("\n");
        }
    }
    if(print[5]){pP_Diagonal(); printf("\n");}
    if(print[6]){pN_Diagonal(); printf("\n");}
    return 0;
}
