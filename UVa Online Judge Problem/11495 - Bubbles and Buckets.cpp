#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int a[100100], temp[100100];

void swap(int i, int j){
	int k = a[i];
	a[i] = a[j];
	a[j] = k;
}

int merge_sort(int i, int j){
	if(j == i) return 0;
	if(j-i == 1){
		if(a[i] > a[j]){
			swap(i, j);
			return 1;
		}
		else{
			return 0;
		}
	}
	int x, y, sizex, mid = (i+j)/2, cur = 0;
	int pointx = i, pointy = mid+1;
	x = merge_sort(i, mid);
	y = merge_sort(mid+1, j);
	x += y;
	sizex = mid- i + 1;
	
	while(pointx <= mid && pointy <= j){
		if(a[pointx] < a[pointy]){
			temp[cur++] = a[pointx];
			pointx++;
			sizex--;
		}
		else{
			temp[cur++] = a[pointy];
			pointy++;
			x += sizex;
		}
	}
	if(pointx > mid){
		while(pointy <= j){
			temp[cur++] = a[pointy];
			pointy++;
		}
	}
	else{
		while(pointx <= mid){
			temp[cur++] = a[pointx];
			pointx++;
		}
	}
	cur = 0;
	for(int m = i; m <= j; m++){
		a[m] = temp[cur++];
	}
	return x%2;
}

int main(){
	int k;
	while( (cin >> n) && n){
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		k = merge_sort(0, n-1);
		cout << ( (k==1)?"Marcelo":"Carlos" ) << endl;
	}
}