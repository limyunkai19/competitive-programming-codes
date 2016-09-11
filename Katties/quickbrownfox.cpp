#include <iostream>
#include <cstdlib>

using namespace std;

bool exist[26];

int main(){
    int n;
    cin >> n;

    string s;
    getline(cin, s);
    for(int i = 0; i < n; i++){
        getline(cin, s);
        for(int i = 0; i < 26; i++)
            exist[i] = false;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(isalpha(c)){
                exist[toupper(c)-'A'] = true;
            }
        }

        string missing = "";
        for(int i = 0; i < 26; i++){
            if(!exist[i])
                missing += char(i+'a');
        }

        if(missing == "")
            cout << "pangram" << endl;
        else
            cout << "missing " << missing << endl;
    }

    return 0;
}