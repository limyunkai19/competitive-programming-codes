#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int n;
	double p;
	while(cin >> n >> p){
		printf("%0.0f\n",  pow(p, 1.0/n));
	}

	return 0;
}
