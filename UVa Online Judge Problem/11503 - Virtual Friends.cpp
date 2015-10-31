#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, int> idx;
int p[200010];
int size[200010];

int find_p(int i){
	if(p[i] != i){
		return p[i] = find_p(p[i]);
	}
	return p[i];
}

bool is_same_set(int i, int j){
	return find_p(i) == find_p(j);
}

int unions(int i, int j){
	int pi = find_p(i), pj = find_p(j);
	if(pi != pj){
		size[pj] += size[pi];
		p[pi] = pj;
	}
}

int main(){
	int t, n, i, ia, ib;
	string a, b;
	cin >> t;
	while(t--){
		idx.clear();
		i = 1;
		cin >> n;
		while(n--){
			cin >> a >> b;
			if(idx[a] == 0){
				p[i] = i;
				size[i] = 1;
				idx[a] = i++;
			}
			if(idx[b] == 0){
				p[i] = i;
				size[i] = 1;
				idx[b] = i++;
			}
			ia = idx[a]; ib = idx[b];
			//if(!is_same_set(ia, ib)){
				unions(ia, ib);
				cout << size[find_p(ia)] << endl;
			//}
		}
		
		
	}
	
	return 0;
}