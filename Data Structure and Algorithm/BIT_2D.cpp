// standard 2D bit implemantation
// solve SPOJ problem: http://www.spoj.com/problems/MATSUM/

#include <iostream>
#include <cstring>

using namespace std;

long long bit[2000][2000], n, a[2000][2000];

void update(int x, int y, int v){
    for(int i = x; i <= n; i += i&-i){
        for(int j = y; j <= n; j += j&-j){
            bit[i][j] += v;
        }
    }
}

long long query(int x, int y){
    long long ans = 0;
    for(int i = x; i >= 1; i -= i&-i){
        for(int j = y; j >= 1; j -= j&-j){
            ans += bit[i][j];
        }
    }
    return ans;
}

int query(int x1, int y1, int x2, int y2){
    x1--; y1--;
    return query(x2, y2) - query(x2, y1) - query(x1, y2) + query(x1, y1);
}


int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        memset(bit, 0, sizeof bit);
        memset(a, 0, sizeof a);

        char type[10];
        scanf("%s", type);
        while(type[0] != 'E'){
            if(type[2] == 'M'){
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                printf("%d\n", query(x1+1, y1+1, x2+1, y2+1));
            }
            else{
                int x, y, v;
                scanf("%d %d %d", &x, &y, &v);
                x++; y++;
                update(x, y, v - a[x][y]);
                a[x][y] = v;
            }

            scanf("%s", type);
        }
        printf("\n");
    }

    return 0;
}