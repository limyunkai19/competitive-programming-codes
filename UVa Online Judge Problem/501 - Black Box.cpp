#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> ii;

int add[30010], get[30010];
set<ii> s;
set<ii>::iterator it, cur;
int t, a, g, x;


int main() {
	// your code goes here
	cin >> t;
	while(t--){
		s.clear();
		s.insert( ii(2000000010, 2000000010) );
		cin >> a >> g;
		for(int i = 0; i < a; i++){
			cin >> add[i];
		}
		for(int i = 0; i < g; i++){
			cin >> get[i];
		}
		it = s.begin();
		x = 0;
		for(int i = 1; i <= a; i++){
			s.insert( ii(add[i-1], i));
			if(add[i-1] < it->first){
				it--;
			}
			
			while(get[x] == i && x < g){
				cout << (it->first) << endl;
				it++;
				x++;
			}
		}
		
		
		if(t != 0){
			cout << endl;
		}
	}
	
	return 0;
}