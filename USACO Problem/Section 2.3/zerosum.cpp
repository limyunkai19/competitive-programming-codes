/*
ID: yunkai91
LANG: C++
TASK: zerosum
*/

#include <iostream>
#include <cstdio>

using namespace std;

int n;
string op[3] = {" ", "+", "-"};

int eval(string expression){
    expression += '.';
    int total = 0;
    int num = 0;
    char op = '+';
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == ' ') continue;
        if(isdigit(expression[i])){
            num = num*10 + expression[i]-'0';
        }
        else{
            if(op == '+'){
                total += num;
            }
            else{
                total -= num;
            }
            num = 0;
            op = expression[i];
        }
    }
    return total;
}

void find(int num, string expression){
    if(num == n+1){
        if(eval(expression) == 0){
            cout << expression << endl;
        }
        return;
    }
    for(int i = 0; i < 3; i++){
        string newexp = expression + op[i];
        newexp += num+'0';
        find(num+1, newexp);
    }
}

int main(){
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    cin >> n;
    find(2, "1");

    return 0;
}