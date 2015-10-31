#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	freopen("piratein.txt", "r", stdin);
	freopen("pirateout.txt", "w", stdout);
	int l, a, b;
	cin >> l >> a >> b;
	cout << min(a+b, 2*l-a-b) << endl;
}