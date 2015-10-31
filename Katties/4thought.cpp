#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char sign[4] = {'+', '-', '*', '/'};

int eval(vector<int> &num, vector<int> &op){
    vector<int> numonepass, oponepass;
    numonepass.push_back(num[0]);
    for(int i = 0; i < 3; i++){
        if(op[i] == 2){
            // mul
            *(numonepass.end()-1) *= num[i+1];
        }
        else if(op[i] == 3){
            // div
            *(numonepass.end()-1) /= num[i+1];
        }
        else{
            numonepass.push_back(num[i+1]);
            oponepass.push_back(op[i]);
        }
    }
    int ans = numonepass[0];
    for(int i = 0; i < oponepass.size(); i++){
        if(oponepass[i] == 0){
            ans += numonepass[i+1];
        }
        else{
            ans -= numonepass[i+1];
        }
    }
    return ans;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> four, op;
        for(int i = 0; i < 4; i++) four.push_back(4);

        bool ans = false;
        for(int i = 0; i < 4 && !ans; i++){
            op.push_back(i);
            for(int j = 0; j < 4 && !ans; j++){
                op.push_back(j);
                for(int k = 0; k < 4 && !ans; k++){
                    op.push_back(k);
                    if(eval(four, op) == n){
                        cout << 4 << ' ' << sign[op[0]] << ' '
                             << 4 << ' ' << sign[op[1]] << ' '
                             << 4 << ' ' << sign[op[2]] << ' '
                             << 4 << " = " << eval(four, op) << endl;
                        ans = true;
                    }
                    op.pop_back();
                }
                op.pop_back();
            }
            op.pop_back();
        }
        if(!ans)
            cout << "no solution" << endl;
    }

    return 0;
}