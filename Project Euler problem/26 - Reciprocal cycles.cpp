#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<int, int> used;

int main()
{
    //freopen("test.txt", "w", stdout);
    int rmd, dig, idx, max_len = 0, max_d;
    string cur, pat;
    //int used[10];
    for(int i = 1; i < 1000; i++){
        rmd = 1;
        while(rmd*10 <= i){
            rmd *= 10;
        }
        //cout << i << " " << rmd << endl;

        /*rmd *= 10;
        dig = rmd/i;
        rmd %= i;
        pat.clear();
        pat += dig + '0';
        cur.clear();
        idx = 0;*/
        //memset(used, 0, sizeof used);
        used.clear();
        for(int j = 0; j < 10000; j++){
            rmd *= 10;
            rmd %= i;
            if(rmd == 0){
                break;
            }
            if(used[rmd]){
                //max_len = max(max_len, (j - used[rmd] + 1) );
                if((j - used[rmd] + 1) > max_len){
                    max_len = (j - used[rmd] + 1);
                    max_d = i;
                }
                //cout << j << endl;
                //cout << i << " : " << (j - used[rmd] + 1) << endl;
                break;
            }
            else{
                used[rmd] = j+1;
            }
            /*cout << "pat:" << pat << " cur: " << cur << endl;
            if(dig == (pat[idx] - '0')){
                cur += dig + '0';

                if(cur == pat){
                    max_len = max(max_len, int(pat.size()));
                    break;
                }
                else{
                    idx++;
                }
            }
            else{
                pat += cur;
                cur.clear();
                idx = 0;
            }*/
        }
    }
    cout << max_d << endl;

    return 0;
}
