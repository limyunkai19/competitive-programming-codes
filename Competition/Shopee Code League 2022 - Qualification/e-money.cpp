#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> name(n);
	unordered_map<string, long long> acc;
	string s1, s2;
	int v;

	for(int i = 0; i < n; i++) {
		cin >> name[i] >> v;
		acc[name[i]] = v;
	}

	for(int i = 0; i < m; i++) {
		cin >> s1 >> s2 >> v;
		if(v > acc[s1]) continue;

		acc[s1] -= v;
		acc[s2] += v;
	}

	sort(name.begin(), name.end());
	for(int i = 0; i < name.size(); i++) {
		cout << name[i] << ' ' << acc[name[i]] << "\n";
	}

	return 0;
}
