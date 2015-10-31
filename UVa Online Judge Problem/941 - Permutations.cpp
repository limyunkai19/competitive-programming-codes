#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long fac[21];
vector<char> ans;
string temp;

void fill_fac(){
    fac[0] = 1;
    for(int i = 1; i <= 20; i++){
        fac[i] = fac[i-1]*i;
    }
}

int main(){
	int tc;
	long long permute, pot;
	char tmp[30];
	fill_fac();
	cin >> tc;
	for(int i = 0; i < tc; i++){
        cin >> temp >> permute;
        for(int j = 0; j < temp.size(); j++){
            ans.push_back(temp.at(j));
        }
        sort(ans.begin(), ans.end());
        while(!ans.empty()){
            pot = permute/fac[ans.size()-1];
            cout << ans[pot];
            permute -= pot*fac[ans.size()-1];
            ans.erase(ans.begin()+pot);
        }
        cout << endl;
	}
	return 0;
}
