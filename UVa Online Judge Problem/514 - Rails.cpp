#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
	stack<int> train;
	int n, a = 1, pointer;
	bool first = true, ans;
	while(cin >> n && n!= 0){
		//cout << n << endl;
		if(!first){
			//cout << "\n";
		}
		first = false;
		while(1){
			//cout << n << endl;
			pointer = 1;
			while(!train.empty()) train.pop();
			train.push(0);
			for(int i = 0; i < n; i++){
				cin >> a;
				if(a == 0) break;
				while(a >= pointer && pointer <= n){
					train.push(pointer);
					pointer++;
				}
				if(train.top() == a){
					train.pop();
				}
			}
			if(a == 0) break;
			cout << ((!train.top())?"Yes":"No") << endl;
		}
		cout << "\n";
	}
	return 0;
}