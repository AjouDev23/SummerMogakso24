import sys

n = int(sys.stdin.readline())
done = False

for i in range(1, n + 1):
    if n % i != 0:
        continue
    for j in range(1, n + 3):
        if (n + 2) % j != 0:
            continue
        if (n // i) * -j + i * ((n + 2) // j) == n + 1:
            done = True
            a = i; b = -j; c = n // i; d = (n + 2) // j
        if (n // i) * j + i * -((n + 2) // j) == n + 1:
            done = True
            a = i; b = j; c = n // i; d = -((n + 2) // j)
        if done:
            break
    if done:
        break
if done:
    print(a, end=" ")
    print(b, end=" ")
    print(c, end=" ")
    print(d)
else:
    print(-1)