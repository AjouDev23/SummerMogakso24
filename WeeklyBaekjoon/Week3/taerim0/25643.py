import sys

N, M = map(int, sys.stdin.readline().split())
base = sys.stdin.readline().strip()

result = True

for _ in range(N - 1):
    new = sys.stdin.readline().strip()
    canStack = False
    for i in range(M):
        if base[-1 - i:] == new[:1 + i] or new[-1 - i:] == base[:i + 1]:
            canStack = True
            break
    if not canStack:
        result = False
    base = new

if result:
    print(1)
else:
    print(0)