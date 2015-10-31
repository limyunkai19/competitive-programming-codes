#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int N;
	bool first = true;
	while( (cin >> N) && N != 0){
		if(first){
			first = false;
		}
		else{
			cout << endl;
		}
		int result, ans;
		bool used[10] = {0}, sol = false;
		for(int f = 0; f <= 9; f++){
			for(int g = 0; g <= 9; g++){
				for(int h = 0; h <= 9; h++){
					for(int i = 0; i <= 9; i++){
						for(int j = 0; j <= 9; j++){
							used[0] = used[1] = used[2] = used[3] = used[4] = 0;
							used[5] = used[6] = used[7] = used[8] = used[9] = 0;
							result = N*(j + i*10 + h*100 + g*1000 + f*10000);
							used[j] = used[i] = used[h] = used[g] = used[f] = 1;
							if(result > 99999 || result < 10000){
								continue;
							}
							while(result > 0){
								used[result%10] = 1;
								result /= 10;
							}
							ans = 0;
							for(int a = 0; a < 10; a++){
								ans += used[a];
							}
							if(ans == 10){
								sol = true;
								cout << N*(j + i*10 + h*100 + g*1000 + f*10000) << " / " << f << g << h << i << j << " = " << N << endl;
							}
						}
					}
				}
			}
		}
		if(!sol){
			cout << "There are no solutions for " << N << '.' << endl;
		}
	}	

	return 0;
}
