#include <iostream>
#include <map>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ifstream word("words.txt");
	freopen("anagin.txt", "r", stdin);
	freopen("anagout.txt", "w", stdout);
	
	string a, b;
	map<string, int> mp;
	vector<string> anagram;
	anagram.push_back("No anagram found");
	int idx = 1;
	while(word >> a && a != "#"){
		b = a;
		sort(b.begin(), b.end());
		if(mp[b] == 0){
			mp[b] = idx++;
			anagram.push_back(a);
		}
		else{
			anagram[mp[b]] += " " + a;
		}
	}
	char c[100];
	while(gets(c) && c[0] != '#'){
		b = "";
		for(int i = 0; c[i] != '\0'; i++){
			if(isalpha(c[i])){
				b += c[i];
			}
		}
		sort(b.begin(), b.end());
		//cout << anagram[mp[b]] << endl;
		printf("%s\n", anagram[mp[b]].c_str());
	}
	return 0;
}

