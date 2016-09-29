n = int(input())

while n != 0:
    ans = []
    pow3 = 1
    n -= 1

    while n > 0:
        if n % 2 == 1:
            ans.append(str(pow3))
        n //= 2
        pow3 *= 3

    print("{ " + ", ".join(ans) + " }")

    n = int(input())
