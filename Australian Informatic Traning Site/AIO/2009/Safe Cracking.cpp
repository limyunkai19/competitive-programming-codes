#include <iostream>
#include <cstdio>

using namespace std;

int safe[100100], safediff[100100], code[100], codediff[100];

int main(){
	freopen("safein.txt", "r", stdin);
	freopen("safeout.txt", "w", stdout);
	
	int a, b;
	//cin >> a >> b;
	scanf("%d %d", &a, &b);
	
	//cin >> safe[0];
	scanf("%d", safe);
	for(int i = 1; i < a; i++){
		//cin >> safe[i];
		scanf("%d", safe+i);
		safediff[i] = safe[i]-safe[i-1];
	}
	
	//cin >> code[0];
	scanf("%d", code);
	for(int i = 1; i < b; i++){
		//cin >> code[i];
		scanf("%d", code+i);
		codediff[i] = code[i]-code[i-1];
	}
	
	int diff = -1;
	for(int i = 1; i < a+b+1; i++){
		for(int j = 1; j < b; j++){
			if(safediff[i+j-1] != codediff[j]){
				break;
			}
			if(j == b-1){
				diff = safe[i+j-1] - code[j];
			}
		}
		if(diff >= 0){
			break;
		}
	}
	for(int i = 0; i < a; i++){
		//cout << safe[i]-diff << endl;
		printf("%d\n", safe[i]-diff);
	}
	
	return 0;
}