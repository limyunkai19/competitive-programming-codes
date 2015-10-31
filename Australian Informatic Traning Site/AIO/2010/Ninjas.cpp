#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("ninjain.txt", "r", stdin);
	freopen("ninjaout.txt", "w", stdout);
	
	int n, k, caught;
	cin >> n >> k;
	if(n%(k+1) == 0){
		caught = n/(k+1);
	}
	else{
		caught = n/(k+1) + 1;
	}
	cout << n-caught << endl;
	
	return 0;
}