#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	while(cin >> a >> b >> c){
		if(a == b && a == c){
			cout << '*' << endl;
		}
		else if(a == b){
			cout << 'C' << endl;
		}
		else if(a == c){
			cout << 'B' << endl;
		}
		else{
			cout << 'A' << endl;
		}
	}
	return 0;
}