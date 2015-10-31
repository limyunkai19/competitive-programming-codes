#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int tc, a, b, c;
    scanf("%d", &tc);
    for(int i = 0; i < tc; i++){
        scanf("%d%d%d", &a, &b, &c);
        printf("Case %d: %d\n", i+1, a+b+c-min(min(a, b), min(a, c))-max(max(a, b), max(a, c)));
    }

    return 0;
}
