#include <iostream>
using namespace std;
 
char change[30];
 
int main() {
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int r;
		cin >> r;
		for(int i = 0; i < 30; i++){
			change[i] = i;
		}
		char a, b;
		while(r--){
			cin >> a >> b;
			a -= 'A'; b -= 'A';
			for(int i = 0; i < 26; i++){
				if(change[i] == b)
					change[i] = a;
			}
		}
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '_') cout << '_';
			else cout << (char)(change[s[i]-'A']+'A');
		}
		cout << endl;
	}
	return 0;
}