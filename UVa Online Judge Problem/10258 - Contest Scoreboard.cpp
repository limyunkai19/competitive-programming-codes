#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

int solved[110][20];
int tim[110][20];
vector<int> ans(110);

inline bool comp(int a, int b){
	if(solved[a][0] != solved[b][0]){
		return solved[a][0] > solved[b][0];
	}
	else if(tim[a][0] != tim[b][0]){
		return tim[a][0] < tim[b][0];
	}
	else{
		return a < b;
	}
}

int main(){
	int t, contestant, problem, times;
	string a;
	char type;
	cin >> t;
	getline(cin, a);
	getline(cin, a);
	while(t--){
		memset(solved, 0, sizeof solved);
		memset(tim, 0, sizeof tim);
		while(getline(cin, a)){
			if(a.size() < 3) break;
			stringstream line(a);
			line >> contestant >> problem >> times >> type;
			if(!solved[contestant][0]){
				solved[contestant][0] = 1;
			}
			if(type == 'I'){
				tim[contestant][problem] += 20;
			}
			else if(type == 'C' && !solved[contestant][problem]){
				//cout << contestant << ' ' << problem << endl;
				solved[contestant][problem] = 1;
				solved[contestant][0]++;
				tim[contestant][0] += tim[contestant][problem]+times;
			}
		}
		for(int i = 0; i <= 103; i++){
			ans[i] = i;
		}
		sort(ans.begin(), ans.end(), comp );
		for(int i = 0; i <= 103; i++){
			if(ans[i] == 0){
				break;
			}
			cout << ans[i] << ' ' << solved[ans[i]][0]-1 << ' ' << tim[ans[i]][0] << endl;
		}
		if(t != 0)
			cout << endl;
	}
}
