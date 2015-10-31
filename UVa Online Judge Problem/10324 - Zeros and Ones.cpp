#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int counter[1000010];

int main(){
    //freopen("data.txt", "r", stdin);
    char bit[1000010];
    int q, a, b, tc = 0;
    while(gets(bit)){
        //if(bit == "" || bit == "\n" || bit.size() == 0) break;
        //cout << bit << endl;
        int len = strlen(bit);
        //cout << bit << " " << len << endl;
        //cout << counter[0];
        for(int i = 1; i < len; i++){
            if(bit[i] == bit[i-1]){
                counter[i] = counter[i-1]+1;
                //cout << counter[i];
            }
            else{
                counter[i] = 0;
                //cout << counter[i];
            }
        }
        //cout << endl;
        scanf("%d", &q);
        printf("Case %d:\n", ++tc);
        while(q--){
            scanf("%d %d", &a, &b);
            if(counter[max(a, b)] - counter[min(a, b)] == max(a, b) - min(a, b)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        getchar();

    }

	return 0;
}

/*char ch [1000010];
int a [1000010];

int main ()
{
    int cases = 0;

    while ( gets (ch) ) {

        int len = strlen (ch);

        if ( len == 0 ) break;

        a [0] = ch [0] == '1' ? 1 : 0;

        for ( int i = 1; i < len; i++ )
            a [i] = ch [i] == '1' ? a [i - 1] + 1 : a [i - 1];

        int n; scanf ("%d", &n);
        printf ("Case %d:\n", ++cases);

        while ( n-- ) {
            int p, q; scanf ("%d %d", &p, &q);

            if ( p > q ) swap (p, q);

            if ( ch [p] == '0' && ch [q] == '0' && a [q] - a [p] == 0 ) printf ("Yes\n");
            else if ( ch [p] == '1' && ch [q] == '1' && a [q] - a [p] == q - p ) printf ("Yes\n");
            else printf ("No\n");
        }

        getchar ();
    }
    return 0;
}*/
