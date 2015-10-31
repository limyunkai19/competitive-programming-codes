#include <iostream>

using namespace std;

int p[300000], num[300000], sum[300000];

void init(int n){
	for(int i = 1; i <= n; i++){
		p[i] = n+i;
	}
	for(int i = n+1; i <= 2*n; i++){
		p[i] = i;
		num[i] = 1;
		sum[i] = i-n;
	}
}

int p_set(int x){
	if(p[x] != x){
		return p[x] = p_set(p[x]);
	}
	return p[x];
}

bool is_same_set(int x, int y){
	return ( p_set(x) == p_set(y) );
}

void union_set(int x, int y){
	if(is_same_set(x, y)){
		return;
	}
	
	num[p_set(y)] += num[p_set(x)];
	sum[p_set(y)] += sum[p_set(x)];
	p[p_set(x)] = p_set(y);
}

void move_to_set(int x, int y){
	if(is_same_set(x, y)){
		return;
	}
	num[p_set(x)]--;
	sum[p_set(x)] -= x;
	num[p_set(y)]++;
	sum[p_set(y)] += x;
	p[x] = p_set(y);
}



int main() {
	int n, m, type, a, b;
	while(cin >> n >> m){
		init(n);
		while(m--){
			cin >> type;
			if(type == 1){
				cin >> a >> b;
				union_set(a, b);
			}
			else if(type == 2){
				cin >> a >> b;
				move_to_set(a, b);
			}
			else{
				cin >> a;
				b = p_set(a);
				cout << num[b] << ' ' << sum[b] << endl;
			}
		}
	}
	return 0;
}