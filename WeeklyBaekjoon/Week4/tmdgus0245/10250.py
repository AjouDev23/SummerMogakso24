N = int(input())
for _ in range(N):
    H,W,N = map(int,input().split())
    if not(N % H):
        floor = H
        room = N // H-1
    else:
        floor = N % H
        room = N // H
    print(floor * 100 + room + 1)