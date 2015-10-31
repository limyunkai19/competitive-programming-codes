#include <cstdio>
#include <cstring>

using namespace std;

int age[102];

int main(){
	int n, a;
	bool first;
	while(scanf("%d", &n) && n){
		memset(age, 0, sizeof age);
		while(n--){
			scanf("%d", &a);
			age[a]++;
		}
		first = false;
		for(int i = 0; i < 102; i++){
			for(int j = 0; j < age[i]; j++){
				if(first)
					printf(" %d", i);
				else{
					printf("%d", i);
					first = true;
				}
			}
		}
		printf("\n");
	}
}