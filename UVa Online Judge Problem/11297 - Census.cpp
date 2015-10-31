#include <iostream>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;

int maxst[2000][2000], minst[2000][2000], table[600][600], n, m, x1, x2, y1, y2, v;

void inity(int node, int yi, int yj, int x, int xnode){
	if(yi == yj){
		minst[xnode][node] = table[x][yi];
		maxst[xnode][node] = table[x][yi];
		return;
	}
	
	int left = 2*node, right = 2*node+1, mid = (yi+yj)/2;
	inity(left, yi, mid, x, xnode);
	inity(right, mid+1, yj, x, xnode);
	
	maxst[xnode][node] = max(maxst[xnode][left], maxst[xnode][right]);
	minst[xnode][node] = min(minst[xnode][left], minst[xnode][right]);
	return;
}

void merge(int node, int yi, int yj, int leftx, int rightx, int xnode){
	if(yi == yj){
		minst[xnode][node] = min(minst[leftx][node], minst[rightx][node]);
		maxst[xnode][node] = max(maxst[leftx][node], maxst[rightx][node]);
		return;
	}
	
	int left = 2*node, right = 2*node+1, mid = (yi+yj)/2;
	merge(left, yi, mid, leftx, rightx, xnode);
	merge(right, mid+1, yj, leftx, rightx, xnode);
	
	minst[xnode][node] = min(minst[leftx][node], minst[rightx][node]);
	maxst[xnode][node] = max(maxst[leftx][node], maxst[rightx][node]);
	return;
}

void init(int node, int xi, int xj){
	if(xi == xj){
		inity(1, 0, m-1, xi, node);
		return;
	}
	
	int left = 2*node, right = 2*node+1, mid = (xi+xj)/2;
	init(left, xi, mid);
	init(right, mid+1, xj);
	
	//merge(1, 0, m-1, left, right, node);
	for(int i = 0; i < 4*n; i++){
		minst[node][i] = min(minst[left][i], minst[right][i]);
		maxst[node][i] = max(maxst[left][i], maxst[right][i]);
	}
	return;
}

ii yquery(int node, int yi, int yj, int xnode){
	if(yj < y1 || yi > y2){
		return ii(-1, -1);
	}
	if(y1 <= yi && yj <= y2){
		return ii(maxst[xnode][node], minst[xnode][node]);
	}
	
	ii lval = yquery(2*node, yi, (yi+yj)/2, xnode);
	ii rval = yquery(2*node+1, (yi+yj)/2+1, yj, xnode);
	
	if(lval.first == -1){
		return rval;
	}
	if(rval.second == -1){
		return lval;
	}
	
	return ii(max(lval.first, rval.first), min(lval.second, rval.second));
}

ii query(int node, int xi, int xj){
	if(xj < x1 || xi > x2){
		return ii(-1, -1);
	}
	if(x1 <= xi && xj <= x2){
		return yquery(1, 0, m-1, node);
	}
	
	ii lval = query(2*node, xi, (xi+xj)/2);
	ii rval = query(2*node+1, (xi+xj)/2+1, xj);
	
	if(lval.first == -1){
		return rval;
	}
	if(rval.second == -1){
		return lval;
	}
	
	return ii(max(lval.first, rval.first), min(lval.second, rval.second));
}


void updatey(int node, int yi, int yj, int xnode){
//cout << yi << ' ' << yj << endl;
	if(yj < y1 || yi > y2){
		return;
	}
	if(y1 <= yi && yj <= y2){
		maxst[xnode][node] = v;
		minst[xnode][node] = v;
		return;
	}
	
	int left = 2*node, right = 2*node+1, mid = (yi+yj)/2;
	updatey(left, yi, mid, xnode);
	updatey(right, mid+1, yj, xnode);
	
	maxst[xnode][node] = max(maxst[xnode][left], maxst[xnode][right]);
	minst[xnode][node] = min(minst[xnode][left], minst[xnode][right]);
	return;
}

void merge_update(int node, int yi, int yj, int leftx, int rightx, int xnode){
	if(yj < y1 || yi > y2){
		return;
	}
	if(y1 <= yi && yj <= y2){
		minst[xnode][node] = min(minst[leftx][node], minst[rightx][node]);
		maxst[xnode][node] = max(maxst[leftx][node], maxst[rightx][node]);
		return;
	}
	
	int left = 2*node, right = 2*node+1, mid = (yi+yj)/2;
	merge_update(left, yi, mid, leftx, rightx, xnode);
	merge_update(right, mid+1, yj, leftx, rightx, xnode);
	
	minst[xnode][node] = min(minst[leftx][node], minst[rightx][node]);
	maxst[xnode][node] = max(maxst[leftx][node], maxst[rightx][node]);
	return;
}

void update(int node, int xi, int xj){
//cout << xi << ' ' << xj << endl;
	if(xj < x1 || xi > x2){
		return;
	}
	if(x1 <= xi && xj <= x2){
		updatey(1, 0, m-1, node);
		return;
	}
	
	int left = 2*node, right = 2*node+1, mid = (xi+xj)/2;
	update(left, xi, mid);
	update(right, mid+1, xj);
	
	merge_update(1, 0, m-1, left, right, node);
	return;
}


int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> table[i][j];
		}
	}
	init(1, 0, n-1);
	int q;
	char type;
	ii ans;
	cin >> q;
	while(q--){
		cin >> type;
		if(type == 'q'){
			cin >> x1 >> y1 >> x2 >> y2;
			y1--;x1--;y2--;x2--;
			ans = query(1, 0, n-1);
			cout << ans.first << ' ' << ans.second << endl;
		}
		else{
			cin >> x1 >> y1 >> v;
			x1--;y1--;x2=x1;y2=y1;
			update(1, 0, n-1);
		}
	}
	return 0;
}