N, M = map(int,input().split())
A = [ 0 for _ in range(N)]
B = [ 0 for _ in range(N)]
count=0
for i in range(N):
    A[i] = list(map(int,list(input())))
for j in range(N):
    B[j] = list(map(int,list(input())))
if N<3 or M<3:
    for y in range(N):
        for x in range(M):
            if A[y][x] != B[y][x]:
                exit(print(-1))
    exit(print(0))        
for y in range(N-2):
    for x in range(M-2):
        if B[y][x] != A[y][x]:
            count+=1
            for cy, cx in [(y,x),(y,x+1),(y,x+2),(y+1,x),(y+1,x+1),(y+1,x+2),(y+2,x),(y+2,x+1),(y+2,x+2)]:
                if A[cy][cx] == 1:
                    A[cy][cx] = 0
                else:
                    A[cy][cx] = 1
if A == B:
    print(count)
else:
    print(-1)