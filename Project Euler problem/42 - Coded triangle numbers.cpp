#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector<string> words;
int idx = 0, min_pro = 0, num = 0;
set<int> tri;

void test_tri(int n){
    if(n > min_pro){
        while(min_pro < n){
            idx++;
            min_pro = idx*(idx+1)/2;
            tri.insert(min_pro);
        }
    }
    if(tri.find(n) != tri.end()){
        num++;
    }
}

int main()
{
    freopen("words.txt", "r", stdin);
    char a;
    cin >> a;
    int s = 0;
    while(cin >> a){
        if(a == '"'){
            cin >> a;
            cin >> a;
            test_tri(s);
            s = 0;
        }
        else{
            s += a - 'A' + 1;
        }
    }
    cout << num << endl;

    return 0;
}
