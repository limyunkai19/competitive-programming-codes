#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	freopen("handin.txt", "r", stdin);
	freopen("handout.txt", "w", stdout);
	
	int n, ball, k, a, b;
	cin >> n >> ball >> k;
	while(k--){
		cin >> a >> b;
		if(a < ball){
			if(b >= ball){
				ball--;
			}
		}
		else if(a > ball){
			if(b <= ball){
				ball++;
			}
		}
		else{	//a == ball
			ball = b;
		}
	}
	cout << ball << endl;
	
	return 0;
}