#include <iostream>
#include <cstdio>

using namespace std;

long long target;
bool ans;
char brac;

bool readtree(long long parentsum, bool gotopen){
	//cout << parentsum << endl;
	long long num;
	bool neg = false;;
	if(gotopen){
		cin >> brac;
	}
	cin >> brac;
	if(brac == ')'){
		return 0;
	}
	if(brac == '-'){
		neg = true;
		cin >> brac;
	}
	
	num = (brac - '0');
	while(cin >> brac && brac != '('){
		num = num*10 + (brac - '0');
	}
	if(neg){ num *= -1; }
	if(readtree(num+parentsum, 0)+readtree(num+parentsum, 1) == 0){
		//cout << parentsum+num << endl;
		if(parentsum+num == target){
			ans = 1;
		}
	}
	cin >> brac;
	return 1;
	
}

int main(){
	while(cin >> target){
		ans = 0;
		readtree(0, 1);
		cout << (ans?"yes":"no") << endl;
	}
}