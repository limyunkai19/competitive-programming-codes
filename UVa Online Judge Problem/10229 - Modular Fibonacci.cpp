#include <iostream>
#include <cstring>

using namespace std;

long long fib_mat[32][4];
long long P2[22];

// 0 1 2 3
// a b c d

long long fib(int n){
	long long a0, a1, a2, a3, b0, b1, b2, b3;
    long long ans[4] = {1, 0, 0, 1};
    for(int i = 0; i < 31; i++){
		if(n&(1<<i)){
			//cout << i << endl;
			a0 = ans[0]; a1 = ans[1];
			a2 = ans[2]; a3 = ans[3];
			b0 = fib_mat[i+1][0]; b1 = fib_mat[i+1][1];
			b2 = fib_mat[i+1][2]; b3 = fib_mat[i+1][3];

			ans[0] = (a0*b0+a1*b2)%P2[21];
			ans[1] = (a0*b1+a1*b3)%P2[21];
			ans[2] = (a2*b0+a3*b2)%P2[21];
			ans[3] = (a2*b1+a3*b3)%P2[21];

			//cout << ans[0] << ' ' << ans[1] << endl << ans[2] << ' ' << ans[3] << endl;
		}
    }
    return ans[1];
}

int main()
{
    P2[0] = 1;
    P2[1] = 2;
    for(int i = 2; i < 22; i++){
		P2[i] = P2[i-1]*2;
    }
    fib_mat[1][0] = 1; fib_mat[1][1] = 1;
    fib_mat[1][2] = 1; fib_mat[1][3] = 0;
    long long a = 1, b = 1, c = 1, d = 0;
    for(int i = 2; i < 32; i++){
    	a = fib_mat[i-1][0]; b = fib_mat[i-1][1];
    	c = fib_mat[i-1][2]; d = fib_mat[i-1][3];
		fib_mat[i][0] = (a*a+b*c)%P2[21];
		fib_mat[i][1] = (a*b+b*d)%P2[21];
		fib_mat[i][2] = (c*a+c*d)%P2[21];
		fib_mat[i][3] = (c*b+d*d)%P2[21];
		//cout << fib_mat[i][1] << endl;
    }

    int m, n;
    while(cin >> m >> n){
        cout << (fib(m)%P2[n]) << endl;
    }
    return 0;
}
