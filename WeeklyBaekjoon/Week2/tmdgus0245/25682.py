import sys
N,M,K=map(int,sys.stdin.readline().split())
board = [0]*N
for i in range(N):
    board[i]=sys.stdin.readline().rstrip()
result = 4000000
white=[]
compare=[[0 for _ in range(M)] for _ in range(N)]
for i in range(2000):
    if i%2==0:
        white.append("WB"*2000)
    else:
        white.append("BW"*2000)
for y in range(N):
    for x in range(M):
        if white[y][x]==board[y][x]:
            compare[y][x] = 0
        else:
            compare[y][x] = 1
sum=[[0 for _ in range(M)]for _ in range(N)]
sum[0][0] = compare[0][0]
for i in range(N):
    for j in range(M):
        if i==j==0:
            continue
        elif i==0:
            sum[i][j] = sum[i][j-1]+compare[i][j]
        elif j==0:
            sum[i][j] = sum[i-1][j]+compare[i][j]
        else:
            sum[i][j] = sum[i-1][j]+sum[i][j-1]+compare[i][j] - sum[i-1][j-1]
for y in range(K-1,N):
    for x in range(K-1,M):
        if x==y==K-1:
            result = min(result, min(sum[K-1][K-1],K**2-sum[K-1][K-1]))
        elif y==K-1:
            result = min(result,min(sum[y][x]-sum[y][x-K],K**2-(sum[y][x]-sum[y][x-K])))
        elif x==K-1:
            result = min(result,min(sum[y][x]-sum[y-K][x],K**2-(sum[y][x]-sum[y-K][x])))
        else:
            result = min(result,min(sum[y][x]-sum[y-K][x]-sum[y][x-K]+sum[y-K][x-K],K**2-(sum[y][x]-sum[y-K][x]-sum[y][x-K]+sum[y-K][x-K])))
print(result)