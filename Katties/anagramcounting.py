import sys

for s in sys.stdin:
    c = {}
    ans = 1
    for i in range(len(s)-1):
        ans *= i+1
        x = s[i]
        if x not in c:
            c[x] = 1
        else:
            c[x] += 1
            ans //= c[x]

    print(ans)