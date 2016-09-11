dp_nCk = [[-1 for i in range(51)] for i in range(101)]

def nCk(n, k):
    if dp_nCk[n][k] != -1:
        return dp_nCk[n][k]
    if n == k or k == 0:
        dp_nCk[n][k] = 1
        return 1

    dp_nCk[n][k] = nCk(n-1, k-1)+nCk(n-1, k)
    return dp_nCk[n][k]

def cross(x, y):
    if x < y:
        x, y = y, x

    # x+y choose y
    return nCk(x+y, y)

def solve(tree):
    if len(tree) <= 1:
        return 1

    root, left, right = tree[0], [], []

    for i in range(1, len(tree)):
        if tree[i] < root:
            left.append(tree[i])
        else:
            right.append(tree[i])

    ans = solve(left)*solve(right)*cross(len(left), len(right))

    return ans

import sys

data = sys.stdin.read().splitlines()
for i in range(0, len(data), 2):
    n = int(data[i])

    tree = list(map(int, data[i+1].split(" ")))

    print(solve(tree))

