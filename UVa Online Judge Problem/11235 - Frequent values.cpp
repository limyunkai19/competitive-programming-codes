#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct Range{
	int leftend;
	int rightend;
	int i;
	int j;
	int freq;
	Range(){}
	Range(int a, int b, int c, int d, int e){
		freq = a;
		i = b;
		j = c;
		leftend = d;
		rightend = e;
	}
};


int a[100010];
vector<int> leftend, rightend, freq;
map<int, int> start, end;

int init(int node, int i, int j){
	if(i == j){
		leftend[node] = a[i];
		rightend[node] = a[i];
		freq[node] = 1;
		return freq[node];
	}
	
	int leftnode = 2*node, rightnode = 2*node+1, mid = (i+j)/2, leftval, rightval;
	leftval = init(leftnode, i, mid);
	rightval = init(rightnode, mid+1, j);
	
	leftend[node] = leftend[leftnode];
	rightend[node] = rightend[rightnode];
	freq[node] = max(freq[leftnode], freq[rightnode]);
	
	if(leftend[rightnode] != rightend[leftnode]){
		return freq[node];
	}
	
	int midval = min(end[leftend[rightnode]], j) - max(start[leftend[rightnode]], i) + 1;
	
	freq[node] = max(midval, freq[node]);
	return freq[node];
	
}

Range query(int node, int i, int j, int left, int right){
	//cout << frenode << endl;
	if(i > right || j < left){
		return Range(-1, 0, 0, 0, 0);
	}
	if(i >= left && j <= right){
		return Range(freq[node], i, j, leftend[node], rightend[node]);
	}
	
	int leftnode = 2*node, rightnode = 2*node+1, mid = (i+j)/2;
	Range leftval;
	Range rightval;
	leftval = query(leftnode, i, mid, left, right);
	rightval = query(rightnode, mid+1, j, left, right);
	
	if(leftval.freq == -1){
		return rightval;
	}
	if(rightval.freq == -1){
		return leftval;
	}
	
	Range current;
	
	current.i = i;
	current.j = j;
	current.leftend = leftval.leftend;
	current.rightend = rightval.rightend;
	current.freq = max(leftval.freq, rightval.freq);
	
	if(leftval.rightend != rightval.leftend){
		return current;
	}
	
	int midval = min(end[rightval.leftend], right) - max(start[rightval.leftend], left) + 1;
	
	current.freq = max(midval, current.freq);
	return current;

}

int main(){
	int n, q, c, b;
	while(cin >> n && n != 0){
		cin >> q;
		leftend.assign(4*n, 0);
		rightend.assign(4*n, 0);
		freq.assign(4*n, 0);
		start.clear();
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(start[a[i]] == 0){
				start[a[i]] = i;
			}
			end[a[i]] = i;
		}
		start[a[0]] = 0;
		init(1, 0, n-1);
		for(int i = 0; i < q; i++){
			cin >> c >> b;
			cout << query(1, 0, n-1, c-1, b-1).freq << endl;
		}
	}
	return 0;
}