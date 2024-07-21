import sys

N = int(sys.stdin.readline())

stack = []
cnt = 1

for _ in range(N):
    stick = int(sys.stdin.readline())
    stack.append(stick)

nowMax = stack.pop()

for _ in range(N - 1):
    top = stack.pop()
    if top > nowMax:
        nowMax = top
        cnt += 1

print(cnt)