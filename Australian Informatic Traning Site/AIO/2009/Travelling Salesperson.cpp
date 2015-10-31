#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("salesin.txt", "r", stdin);
	freopen("salesout.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	cout << a+b+c-min(min(a, b), c) << endl;
}