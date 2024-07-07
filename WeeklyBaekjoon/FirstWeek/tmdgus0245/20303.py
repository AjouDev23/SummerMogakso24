import sys
N,M,K = map(int,sys.stdin.readline().split())
gr=[[0,0]for _ in range(N)] #[0]->모임, [1]->캔디수
candy=list(map(int,sys.stdin.readline().split()))
for i in range(N):
    gr[i][1]=candy[i]
    gr[i][0]=i
for j in range(M):
    k,l = map(int,sys.stdin.readline().split())
    if(gr[k-1][0]<gr[l-1][0]):
        if(gr[l-1][0]!=l-1):
            t=l
            while(gr[t-1][0]!=t-1):
                l=gr[t-1][0]+1
                gr[t-1][0]=gr[k-1][0]
                t=l
            gr[t-1][0]=gr[k-1][0]
        else:
            gr[l-1][0]=gr[k-1][0]
    else:
        if(gr[k-1][0]!=k-1):
            t=k
            while(gr[t-1][0]!=t-1):
                k=gr[t-1][0]+1
                gr[t-1][0]=gr[l-1][0]
                t=k
            gr[t-1][0]=gr[l-1][0]
        else:
            gr[k-1][0]=gr[l-1][0]
kidsAndCandies=[[0,0]for _ in range(N)]
roots=[[0,0]]
for m in range(N):
    root=m
    while(gr[root][0]!=root):
        root=gr[root][0]
    kidsAndCandies[root][0]+=1
    kidsAndCandies[root][1]+=gr[m][1]
for f in range(N):
    if(kidsAndCandies[f][1]!=0):
        roots.append(kidsAndCandies[f])
dp = [[0]*(K+1) for _ in range(len(roots))]
for i in range(1,len(roots)):
    for j in range(1,K+1):
        kids = roots[i][0]
        candies = roots[i][1]
        if(j<=kids):
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-kids]+candies)
print(dp[len(roots)-1][K])