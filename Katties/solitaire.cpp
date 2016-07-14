#include <iostream>
#include <map>

using namespace std;

int r, c;
map<string, int> memo;

char get_state(string& s, int i, int j){
    // row 0 -> 0
    // row 1 -> c
    // row i -> i*c

    return s[i*c+j];
}

void set_state(string& s, int i, int j, char new_state){
    s[i*c+j] = new_state;
}

int pebble(string& s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
        ans += s[i]=='o';
    return ans;
}

int solve(string s){
    if(memo[s] != 0)
        return memo[s];

    int ans = pebble(s);
    for(int i = 0; i < r; i++){
        // try go right
        for(int j = 0; j < c-2; j++){
            if(get_state(s, i, j) == 'o' && get_state(s, i, j+1) == 'o' && get_state(s, i, j+2) == '.'){
                set_state(s, i, j, '.'); set_state(s, i, j+1, '.'); set_state(s, i, j+2, 'o');
                ans = min(solve(s), ans);
                set_state(s, i, j, 'o'); set_state(s, i, j+1, 'o'); set_state(s, i, j+2, '.');
            }
        }
        // try go left
        for(int j = 2; j < c; j++){
            if(get_state(s, i, j) == 'o' && get_state(s, i, j-1) == 'o' && get_state(s, i, j-2) == '.'){
                set_state(s, i, j, '.'); set_state(s, i, j-1, '.'); set_state(s, i, j-2, 'o');
                ans = min(solve(s), ans);
                set_state(s, i, j, 'o'); set_state(s, i, j-1, 'o'); set_state(s, i, j-2, '.');
            }
        }
    }

    for(int i = 0; i < c; i++){
        // try go down
        for(int j = 0; j < r-2; j++){
            if(get_state(s, j, i) == 'o' && get_state(s, j+1, i) == 'o' && get_state(s, j+2, i) == '.'){
                set_state(s, j, i, '.'); set_state(s, j+1, i, '.'); set_state(s, j+2, i, 'o');
                ans = min(solve(s), ans);
                set_state(s, j, i, 'o'); set_state(s, j+1, i, 'o'); set_state(s, j+2, i, '.');
            }
        }
        // try go up
        for(int j = 2; j < r; j++){
            if(get_state(s, j, i) == 'o' && get_state(s, j-1, i) == 'o' && get_state(s, j-2, i) == '.'){
                set_state(s, j, i, '.'); set_state(s, j-1, i, '.'); set_state(s, j-2, i, 'o');
                ans = min(solve(s), ans);
                set_state(s, j, i, 'o'); set_state(s, j-1, i, 'o'); set_state(s, j-2, i, '.');
            }
        }
    }
    return memo[s] = ans;
}

int main(){
    int n;
    cin >> n;
    string x;
    getline(cin, x) ;
    while(n--){
        r = 0;
        string s;
        while(getline(cin, x) && x != ""){
            s += x;
            r++;
        }
        c = s.size()/r;


        int ans = solve(s);
        cout << ans << ' ' << pebble(s)-ans << endl;
    }

    return 0;
}