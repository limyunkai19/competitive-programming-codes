L, D, X = int(raw_input()), int(raw_input()), int(raw_input())

x = filter(lambda n: sum(map(int, str(n)))==X, [str(n) for n in range(L, D+1)])

print x[0]
print x[-1]