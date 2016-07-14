t = int(raw_input())
for tc in range(1, t+1):
    n = int(raw_input())
    a = map(int, raw_input().split(" "))
    b = map(int, raw_input().split(" "))
    a = sorted(a)
    b = sorted(b)[::-1]

    sum = 0
    for x, y in zip(a, b):
        sum += x*y
    print "Case #%d: "%tc + str(sum)