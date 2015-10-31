#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int w, h, lot1, lot2;

int calc_way(int xmax, int xmin, int ymax, int ymin, int x, int y){
	if(x < xmax-xmin || y < ymax-ymin) return 0;
	int updown, leftright;
	
	leftright = min(w-1, xmin+x-1) - max(0, xmax-x+1) - x + 2;
	updown = min(h-1, ymin+y-1) - max(0, ymax-y+1) - y + 2;

	return leftright*updown;
}

int main()
{
	freopen("mallsin.txt", "r", stdin);
	freopen("mallsout.txt", "w", stdout);
	int x[4], y[4], error = 0, xmax, xmin, ymax, ymin;
	cin >> w >> h >> lot1 >> lot2;
	for(int i = 0; i < 4; i++){
		cin >> x[i] >> y[i];
	}
	
	//error = cannot placed = 
	//U ai = sum ai - sum ai n bi + sum ai n bi n ci - sum ai n bi n ci n di;
	
	for(int a = 0; a < 4; a++){
		error += calc_way(x[a], x[a], y[a], y[a], lot1, lot2);
	}
	
	for(int a = 0; a < 4; a++){
		for(int b = a+1; b < 4; b++){
			xmax = max(x[a], x[b]);
			xmin = min(x[a], x[b]);
			ymax = max(y[a], y[b]);
			ymin = min(y[a], y[b]);
			error -= calc_way(xmax, xmin, ymax, ymin, lot1, lot2);
		}
	}
	
	for(int a = 0; a < 4; a++){
		for(int b = a+1; b < 4; b++){
			for(int c = b+1; c < 4; c++){
				xmax = max(max(x[a], x[b]), x[c]);
				xmin = min(min(x[a], x[b]), x[c]);
				ymax = max(max(y[a], y[b]), y[c]);
				ymin = min(min(y[a], y[b]), y[c]);
				error += calc_way(xmax, xmin, ymax, ymin, lot1, lot2);
			}
		}
	}
	xmax = max(max(x[0], x[1]), max(x[2], x[3]));
	xmin = min(min(x[0], x[1]), min(x[2], x[3]));
	ymax = max(max(y[0], y[1]), max(y[2], y[3]));
	ymin = min(min(y[0], y[1]), min(y[2], y[3]));
	error -= calc_way(xmax, xmin, ymax, ymin, lot1, lot2);

	int total = (w-1 - lot1 + 2)*(h-1 - lot2 + 2);

	cout << total-error << endl;

    return 0;
}
