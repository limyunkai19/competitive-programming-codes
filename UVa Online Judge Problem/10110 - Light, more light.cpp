#include <iostream>
#include <cmath>

using namespace std;

string f(long long x){
	long long r = sqrt(x);
	if(r*r == x){
		return "yes";
	}
	return "no";
}

int main(){
	long long x;
	while(cin >> x && x != 0){
		cout << f(x) << endl;
	}
	return 0;
}