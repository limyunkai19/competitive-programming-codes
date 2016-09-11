#include <iostream>
#include <map>

using namespace std;

#define MOD 1000000007

long long meaning[1010];

string substr(string& s, int length, int back){
    string ans = "";
    for(int i = length-back; i < length; i++){
        ans += s[i];
    }
    return ans;
}

int main(){
    int n;
    string s;
    cin >> n >> s;

    map<string, int> words;
    while(n--){
        string x;
        int m;
        cin >> x >> m;
        words[x] = m;
    }

    // base case, empty size has 1 meaning
    meaning[0] = 1;
    for(int i = 1; i <= s.size(); i++){
        // calculate string wth length i has how many meaning
        for(int back = 1; back <= i; back++){
            meaning[i] += (meaning[i-back]*words[substr(s, i, back)])%MOD;
        }
        meaning[i] %= MOD;
    }

    cout << meaning[s.size()] << endl;


    return 0;
}