#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int A[100010];
vector<int> st;

int build(int left, int right, int node){
	if(left == right)
		return st[node] = A[left];

	int leftNode = 2*node, rightNode = 2*node+1, leftVal, rightVal;

	leftVal  = build(left              , (left+right)/2, leftNode );
	rightVal = build((left+right)/2 + 1, right         , rightNode);

	return st[node] = max(leftVal, rightVal);
}

int query(int left, int right, int node, int i, int j){
	if(right < i || left > j)
		return -1;

	if(left >= i && j >= right)
		return st[node];

	int leftNode = 2*node, rightNode = 2*node+1, leftVal, rightVal;

	leftVal  = query(left              , (left+right)/2, leftNode , i, j);
	rightVal = query((left+right)/2 + 1, right         , rightNode, i, j);

	if(leftVal == -1)
		return rightVal;
	if(rightVal == -1)
		return leftVal;

	return max(leftVal, rightVal);
}

int update(int left, int right, int node, int idx, int newVal){
	if(left > idx || right < idx)
		return st[node];

	if(left == idx && right == idx)
		return st[node] = newVal;

	int leftNode = 2*node, rightNode = 2*node+1, leftVal, rightVal;

	leftVal  = update(left              , (left+right)/2, leftNode , idx, newVal);
	rightVal = update((left+right)/2 + 1, right         , rightNode, idx, newVal);

	return st[node] = max(leftVal, rightVal);
}

int main()
{
	freopen("arbint.in", "r", stdin);
	freopen("arbint.out", "w", stdout);
	int sz, M;
	//cin >> sz >> M;
	scanf("%d%d", &sz, &M);
	st.assign(4*sz, 0);
	for(int i = 0; i < sz; i++){
		//cin >> A[i];
		scanf("%d", &A[i]);
	}
	build(0, sz-1, 1);
	int type, a, b;
	for(int i = 0; i < M; i++){
		//cin >> type >> a >> b;
		scanf("%d%d%d", &type, &a, &b);
		if(type == 0){
			//cout << query(0, sz-1, 1, a-1, b-1) << endl;
			printf("%d\n", query(0, sz-1, 1, a-1, b-1));
		}
		else{
			update(0, sz-1, 1, a-1, b);
		}
	}



    return 0;
}
