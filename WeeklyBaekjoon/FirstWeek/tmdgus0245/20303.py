import sys
N,M,K = map(int,sys.stdin.readline().split())
gr=[[0,0]for _ in range(N)] #[0]->모임, [1]->캔디수
candy=list(map(int,sys.stdin.readline().split()))
for i in range(N):
    gr[i][1]=candy[i]
group=1
for j in range(M):
    k,l = map(int,sys.stdin.readline().split())
    if(gr[k-1][0]==0 and gr[l-1][0]==0):
        gr[k-1][0]=group
        gr[l-1][0]=group
        group+=1
    elif(gr[k-1][0]!=0):
        gr[l-1][0]=gr[k-1][0]
    else:
        gr[k-1][0]=gr[l-1][0]
kidsAndCandies=[[0,0]for _ in range(N)]
for m in range(N):
    kidsAndCandies[gr[m][0]][0]+=1
    kidsAndCandies[gr[m][0]][1]+=gr[m][1]
dp = [[0]*(K+1) for _ in range(group+1)]
for i in range(1,group+1):
    for j in range(1,K+1):
        kids = kidsAndCandies[i][0]
        candies = kidsAndCandies[i][1]
        if(j<=kids):
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-kids]+candies)
print(dp[group][K])