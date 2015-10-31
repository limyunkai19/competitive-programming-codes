#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int mine[110][110];

int main()
{
    int n, m, tc = 1;
    char temp;
    cin >> n >> m;
    while(n != 0){
        memset(mine, 0, sizeof mine);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> temp;
                if(temp == '*'){
                    mine[i][j] = -1;
                    for(int x = -1 ; x <= 1; x++){
                        for(int y = -1; y <= 1; y++){
                            if(mine[i+x][j+y] >= 0){
                                mine[i+x][j+y]++;
                            }
                        }
                    }
                }
            }
        }
        printf("Field #%d:\n", tc++);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(mine[i][j] == -1){
                    cout << "*";
                }
                else{
                    cout << mine[i][j];
                }
            }
            cout << endl;
        }
        cin >> n >> m;
        if(n == 0){
            return 0;
        }
        cout << endl;
    }
    return 0;
}
