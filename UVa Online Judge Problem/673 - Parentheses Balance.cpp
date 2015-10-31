#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int tc;
    cin >> tc; getchar();
    string a;

    while(tc--){
        getline(cin, a);
        stack<char> brac;
        for(int i = 0; i < a.size(); i++){
            if(a.at(i) == ']'){
                if(brac.empty() || brac.top() != '['){
                    brac.push(a.at(i));
                }
                else{
                    brac.pop();
                }
            }
            else if(a.at(i) == ')'){
                if(brac.empty() || brac.top() != '('){
                    brac.push(a.at(i));
                }
                else{
                    brac.pop();
                }
            }
            else{
                brac.push(a.at(i));
            }
        }
        if(brac.empty()){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}
