import sys
N,K=map(int, sys.stdin.readline().split())
ob=[[0,0]for _ in range(N)]
for i in range(N):
    ob[i][0],ob[i][1]=map(int,sys.stdin.readline().split())
dp = [[0]*(K+1) for _ in range(N+1)]
for i in range(1,N+1):
    for j in range(1,K+1):
        weight = ob[i-1][0]
        value = ob[i-1][1]
        if(j<weight):
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight]+value)
print(dp[N][K])