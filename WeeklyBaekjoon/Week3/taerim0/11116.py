import sys

n = int(sys.stdin.readline())

for _ in range(n):
    m = int(sys.stdin.readline())
    cnt = 0
    left_rope = []
    right_rope = []
    for i in range(2):
        times = list(map(int, sys.stdin.readline().split()))
        cars = []
        while len(times):
            if i:
                right_rope.append(times[0] + 250)
            else:
                left_rope.append(times[0] + 250)
            times.pop(times.index(times[0] + 500))
            times.pop(0)
    for time in left_rope:
        if time + 1000 in right_rope:
            cnt += 1
    print(cnt)