#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

int dp[11][30][30];
bool moles_matrix[11][30][30];

int gcd(int a, int b){
    if( a == 0 ) return b;
    if( b == 0 ) return a;

    return gcd(b, a%b);
}

inline int abs(int x){
    if(x < 0) return -x;
    return x;
}

inline bool check(int r, int c, int n){
    if(r < 0 || r >= n+6)
        return false;
    if(c < 0 || c >= n+6)
        return false;
    return true;
}

int main(){
    int n, d, m;
    while(cin >> n >> d >> m && n != 0){
        memset(moles_matrix, 0, sizeof moles_matrix);
        memset(dp, 0, sizeof dp);

        // need offset, sometimes it is benificial to move outside of the board zzz
        while(m--){
            int x, y, t;
            cin >> x >> y >> t;
            moles_matrix[t][y+3][x+3] = true;
        }

        set<ii> gradient_set;
        for(int dr = -d; dr <= d; dr++){
            for(int dc = -d; dc <= d; dc++){
                int d2 = dr*dr + dc*dc;
                if(d2 > d*d || d2 == 0) continue;

                int g = gcd(abs(dr), abs(dc));
                gradient_set.insert(ii(dr/g, dc/g));
            }
        }
        vector<ii> gradient(gradient_set.begin(), gradient_set.end());

        for(int t = 1; t <= 10; t++){

            for(int r = 0; r < n+6; r++){
                for(int c = 0; c < n+6; c++){
                    for(int i = 0; i < gradient.size(); i++){
                        int dr = gradient[i].first, dc = gradient[i].second;
                        int dist = dr*dr + dc*dc, hit = 0;
                        for(int mul = 0; mul*mul*dist <= d*d; mul++){
                            if(!check(r+mul*dr, c+mul*dc, n))
                                break;
                            hit += moles_matrix[t][r+mul*dr][c+mul*dc];
                            dp[t][r+mul*dr][c+mul*dc] = max(dp[t][r+mul*dr][c+mul*dc], dp[t-1][r][c] + hit);
                        }
                    }
                }
            }

        }

        int ans = 0;
        for(int r = 0; r < n+6; r++){
            for(int c = 0; c < n+6; c++){
                ans = max(ans, dp[10][r][c]);
            }
        }
        cout << ans << endl;

    }


    return 0;
}