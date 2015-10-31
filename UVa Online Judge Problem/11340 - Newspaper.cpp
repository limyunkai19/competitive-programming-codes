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
    string line;
    int cost[1350];
    int tc, n, total, price;
    char temp;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> n;   getchar();
        total = 0;
        memset(cost, 0, sizeof cost);
        for(int j = 0; j < n; j++){
            //temp = getchar();
            scanf("%c %d\n", &temp, &price);
            cost[temp+500] = price;
            //cout << int(temp) << price << " " << j << endl;
        }
        cin >> price;
        getchar();
        for(int k = 0; k < price; k++){
            getline(cin, line);
            for(int l = 0; l < line.size(); l++){
                total += cost[line.at(l)+500];
            }
            //printf("line %d\n", k+1);
        }
        printf("%d.%0.2d$\n", total/100, total%100);
    }


    return 0;
}
