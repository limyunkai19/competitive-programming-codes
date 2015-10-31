#include <iostream>
#include <map>

using namespace std;

int main(){
	string a;
	map<string, int> mp;
	int ans;
	while(getline(cin, a)){
		ans = a.size()+1;
		for(int i = 1; i <= a.size()/2; i++){
			mp.clear();			
			for(int j = 0; j+i <= a.size(); j++){
				mp[a.substr(j, i)]++;
				if(mp.size() > i+1){
					ans = min(j+i, ans);
					break;
				}
			}
		}
		if(ans == a.size()+1){
			cout << "YES" << endl;
		}
		else{
			cout << "NO:" << ans << endl;
		}
	}

}