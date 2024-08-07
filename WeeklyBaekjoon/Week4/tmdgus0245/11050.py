N,K = map(int,input().split())
n = N
N = 1
for _ in range(K):
    N *= n
    n-=1
for i in range(2,K+1):
    N /= i
print(int(N))