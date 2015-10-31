#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

inline bool comp(string a, string b){
    return a.size() < b.size();
}

int main()
{
    freopen("buildin.txt", "r", stdin);
    freopen("buildout.txt", "w", stdout);

    string ans[2005], ref[2005];
    bool brac[2005], isref[2005];
    vector<string> mul_ans, add_ans;
    string a;
    int x, y;
    memset(brac, 0, sizeof brac);
    memset(isref, 0, sizeof isref);
    ans[1] = "1"; ans[11] = "11"; ans[111] = "111"; ans[1111] = "1111";
    int n;
    for(int i = 1; i < 2001; i++){
        if(ans[i].size() == 0){
            add_ans.clear();
            mul_ans.clear();
            if(i%111 == 0){
                a.clear();
                a += "111*";
                if(isref[i/111]){
					a += ref[i/111];
                }
                else if(brac[i/111]){
                    a += "(";
                    a += ans[i/111];
                    a += ")";
                }
                else{
                    a += ans[i/111];
                }
                mul_ans.push_back(a);
            }
            if(i%11 == 0){
                a.clear();
                a += "11*";
                if(isref[i/11]){
					a += ref[i/11];
                }
                else if(brac[i/11]){
                    a += "(";
                    a += ans[i/11];
                    a += ")";
                }
                else{
                    a += ans[i/11];
                }
                mul_ans.push_back(a);
            }
            a.clear();
            a += ans[i-1];
            a += "+1";
            add_ans.push_back(a);
            if(i > 11){
                a.clear();
                a += ans[i-11];
                a += "+11";
                add_ans.push_back(a);
            }
            if(i > 111){
                a.clear();
                a += ans[i-111];
                a += "+111";
                add_ans.push_back(a);
            }
            //cout << a << endl;
            for(int div = 2; div < i; div++){
                if(i%div == 0){
                    a.clear();
                    x = div; y = i/div;
                    if(isref[x]){
						a += ref[x];
                    }
                    else if(brac[x]){
                        a += "(";
                        a += ans[x];
                        a += ")";
                    }
                    else{
                        a += ans[x];
                    }
                    a += "*";
                    if(isref[y]){
						a += ref[y];
                    }
                    else if(brac[y]){
                        a += "(";
                        a += ans[y];
                        a += ")";
                    }
                    else{
                        a += ans[y];
                    }
                    //if(i < 10)cout << i << "=" << a << endl;
                    mul_ans.push_back(a);
                }
            }
            sort(mul_ans.begin(), mul_ans.end(), comp);
            sort(add_ans.begin(), add_ans.end(), comp);
            if(mul_ans.size() == 0){
                ans[i] = add_ans[0];
                ref[i] = add_ans[0];
                brac[i] = true;
            }
            else if(mul_ans[0].size() <= add_ans[0].size()){
                ans[i] = mul_ans[0];
                brac[i] = false;
            }
            else if(mul_ans[0].size() == add_ans[0].size()+1 || mul_ans[0].size() == add_ans[0].size()+2){
				ans[i] = add_ans[0];
				ref[i] = mul_ans[0];
				isref[i] = true;
				brac[i] = true;

            }
            else{
                ans[i] = add_ans[0];
                brac[i] = true;
            }
            //if(i < 50)
                //cout << ans[i] << endl;
        }
        printf("%d=%s\n", i, ans[i].c_str());
    }

	scanf("%d", &n);
    //cout << n << endl;
    while(n != 0){
        printf("%d=%s\n", n, ans[n].c_str());
        //cout << brac[n] << endl;

        scanf("%d", &n);
    }

    return 0;
}
