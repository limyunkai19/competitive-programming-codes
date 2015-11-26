#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	stack<long long> seq;
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		while(!seq.empty()) seq.pop();
		long long n, b = 0, w = 0, k, l;
		char cur, pre = ' ';
		cin >> n;
		while(n--){
			cin >> k >> cur;
			
			if(cur == 'B'){
				b += k;
			}
			else{
				w += k;
			}
			if(cur == pre){
				int prek = seq.top(); seq.pop();
				seq.push(prek+k);
			}
			else{
				seq.push(k);
			}
			pre = cur;
		}
		//cout << b << ' ' << w << endl;
		if(b == 0 || w == 0){
			cout << b+w << endl;
			continue;
		}
		long long ratio0, ratio1, turn = 0, ans = 0, num0 = 0, num1 = 0;
		if(pre == 'B'){
			ratio0 = b/gcd(w, b);
			ratio1 = w/gcd(w, b);
		}
		else{
			ratio0 = w/gcd(w, b);
			ratio1 = b/gcd(w, b);
		}
		//cout << ratio0 << ' ' << ratio1 << endl;
		while(!seq.empty()){
			if(turn == 0){
				l = seq.top(); seq.pop(); turn = !turn;
				
				//if can group
				if(num1 != 0 && num1%ratio1 == 0 && num1/ratio1*ratio0 - num0 > 0 && num1/ratio1*ratio0 - num0 <= l){
					num0 += l;
					num0 -= num1/ratio1*ratio0;
					num1 = 0;
					ans++;
				}
				else{
					num0 += l;
				}
			}
			else{
				l = seq.top(); seq.pop(); turn = !turn;
				
				if(num0 != 0 && num0%ratio0 == 0 && num0/ratio0*ratio1 - num1 > 0 && num0/ratio0*ratio1 - num1 <= l){
					num1 += l;
					num1 -= num0/ratio0*ratio1;
					num0 = 0;
					ans++;
				}
				else{
					num1 += l;
				}
			}
			//cout << num0 << ' ' << num1 << ' ' << ans << endl;
		}
		if(num0 + num1 != 0) ans++;
		cout << ans << endl;
	}
	
	return 0;
}
