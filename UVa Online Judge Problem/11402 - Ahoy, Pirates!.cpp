#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int st[4*1024005], lazy[4*1024005];
string pirate;

int init(int node, int i, int j){
	lazy[node] = 0;
	if(i == j){
		return st[node] = (pirate[i]-'0');
	}
	
	int leftnode = 2*node, rightnode = 2*node+1, mid = (i+j)/2;
	
	int lval = init(leftnode, i, mid);
	int rval = init(rightnode, mid+1, j);
	
	return st[node] = (lval + rval);
}

// E -> change range to 1
// F -> change range to 0
// G -> change range to inverse

//lazy 0 -> no lazy
//lazy 1 -> change range to 1
//lazy 2 -> change range to 0
//lazy 3 -> change range to inverse

int change_state(int ori, int changes){
	if(ori == 0){
		return changes;
	}
	if(changes == 1 || changes == 2){
		return changes;
	}
	if(changes == 0){
		return ori;
	}
	if(ori == 1){
		return 2;
	}
	if(ori == 2){
		return 1;
	}
	if(ori == 3){
		return 0;
	}
	
}

int change_val(int val, int i, int j, int type){
	if(type == 0){
		return val;
	}
	if(type == 1){
		return (j-i+1);
	}
	if(type == 2){
		return 0;
	}
	if(type == 3){
		return ((j-i+1)-val) ;
	}
}

int update(int node, int i, int j, int left, int right, int type){
	if(i > right || j < left){
		if(i != j){
			lazy[2*node] = change_state(lazy[2*node], lazy[node]);
			lazy[2*node+1] = change_state(lazy[2*node+1], lazy[node]);
		}
		st[node] = change_val(st[node], i, j, lazy[node]);
		lazy[node] = 0;
		return st[node];
	}
	if(left <= i && j <= right){
		//lazy update this node
		lazy[node] = change_state(lazy[node], type);
		if(i != j){
			lazy[2*node] = change_state(lazy[2*node], lazy[node]);
			lazy[2*node+1] = change_state(lazy[2*node+1], lazy[node]);
		}
		st[node] = change_val(st[node], i, j, lazy[node]);
		lazy[node] = 0;
		return st[node];
	}
	
	int leftnode = 2*node, rightnode = 2*node+1, mid = (i+j)/2;
	//extend lazy to child
	st[node] = change_val(st[node], i, j, lazy[node]);
	lazy[leftnode] = change_state(lazy[leftnode], lazy[node]);
	lazy[rightnode] = change_state(lazy[rightnode], lazy[node]);
	lazy[node] = 0;
	
	int lval = update(leftnode, i, mid, left, right, type);
	int rval = update(rightnode, mid+1, j, left, right, type);
	return (st[node] = lval+rval);
}

int query(int node, int i, int j, int left, int right){
	if(i > right || j < left){
		return -1;
	}
	if(left <= i && j <= right){
		if(i != j){
			lazy[2*node] = change_state(lazy[2*node], lazy[node]);
			lazy[2*node+1] = change_state(lazy[2*node+1], lazy[node]);
		}
		st[node] = change_val(st[node], i, j, lazy[node]);
		lazy[node] = 0;
		return st[node];
	}
	
	int leftnode = 2*node, rightnode = 2*node+1, mid = (i+j)/2;
	st[node] = change_val(st[node], i, j, lazy[node]);
	lazy[leftnode] = change_state(lazy[leftnode], lazy[node]);
	lazy[rightnode] = change_state(lazy[rightnode], lazy[node]);
	lazy[node] = 0;
	
	int lval = query(leftnode, i, mid, left, right);
	int rval = query(rightnode, mid+1, j, left, right);
	
	if(lval == -1){
		return rval;
	}
	if(rval == -1){
		return lval;
	}
	
	return (lval+rval);
}

int main(){
	int t, m, n, p, q, qu;
	char type;
	string tmp;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		cout << "Case " << tc << ":\n";
		pirate = "";
		cin >> m;
		while(m--){
			cin >> p >> tmp;
			while(p--){
				pirate += tmp;
			}
		}
		init(1, 0, pirate.size()-1);
		
		qu = 1;
		cin >> m;
		while(m--){
			cin >> type >> p >> q;
			if(type == 'F'){
				update(1, 0, pirate.size()-1, p, q, 1);
			}
			else if(type == 'E'){
				update(1, 0, pirate.size()-1, p, q, 2);
			}
			else if(type == 'I'){
				update(1, 0, pirate.size()-1, p, q, 3);
			}
			else{
				printf("Q%d: %d\n", qu++, query(1, 0, pirate.size()-1, p, q));
			}
		}
	}
	
	return 0;
}