#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int t, s, d, a, b;
	cin >> t;
	while(t--){
		cin >> s >> d;
		a = s+d;
		if(a%2==1){
			cout << "impossible" << endl;
			continue;
		}
		a /= 2;
		b = s-a;
		if(a >= 0 && b >= 0){
			cout << a << ' ' << b << endl;
		}
		else{
			cout << "impossible" << endl;
		}
	}
}