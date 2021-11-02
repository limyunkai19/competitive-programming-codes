// link: https://csacademy.com/ieeextreme-practice/task/expression/

#include <iostream>
#include <vector>

using namespace std;

constexpr long long mod = 1'000'000'007;

// eval without bracket
string eval(vector<string> token) {
    // check
    if(token.size() % 2 == 0) {
        return "invalid";
    }

    for(int i = 0; i < (int)token.size(); i++) {
        if(i % 2 == 0 && !isdigit(token[i][0]))
            return "invalid";
        if(i % 2 == 1 && isdigit(token[i][0]))
            return "invalid";
        if(token[i] == "(")
            return "invalid";
    }

    // do multiplication first
    vector<long long> val{ stoi(token[0]) };
    for(int i = 2; i < (int)token.size(); i += 2) {
        if(token[i-1] == "*") {
            val.back() = (val.back() * stoll(token[i])) % mod;
        }
        else if(token[i-1] == "-") {
            val.push_back(-stoll(token[i]));
        }
        else {
            val.push_back(stoll(token[i]));
        }
    }

    long long sum = 0;
    for(const long long& v : val) {
        sum += v;
    }
    sum = (sum % mod + mod) % mod;

    return to_string(sum);
}

string eval(string expr) {
    if(expr.size() == 0) {
        return "invalid";
    }

    // eliminate bracket
    vector<string> token;
    for(const char& c : expr) {
        if(c == ')') {
            vector<string> bracketToken;
            while(token.size() > 0 && token.back() != "(") {
                bracketToken.push_back(token.back());
                token.pop_back();
            }
            if(token.size() == 0) {
                return "invalid";
            }
            token.pop_back(); // pop the "("

            string bracketResult = eval(vector<string>(bracketToken.rbegin(), bracketToken.rend()));
            if(bracketResult == "invalid") {
                return bracketResult;
            }
            token.push_back("0" + bracketResult);
            continue;
        }

        if(token.size() == 0 || !isdigit(c)) {
            token.emplace_back(1, c);
            continue;
        }

        // c must be digit at here
        if(isdigit(token.back()[0]) && token.back()[0] != '0') {
            token.back() += c;
        }
        else {
            token.emplace_back(1, c);
        }
    }

    return eval(token);
}

int main() {
    int t; cin >> t;
    while(t--) {
        string expr; cin >> expr;
        cout << eval(expr) << "\n";
    }
    return 0;
}
