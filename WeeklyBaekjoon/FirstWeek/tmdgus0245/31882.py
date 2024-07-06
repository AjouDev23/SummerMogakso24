import sys
N=int(sys.stdin.readline())
S=sys.stdin.readline().rstrip()
geun=1
for i in range(1,N):
    if(i==1):
        for j in range(N-1):
            if(S[j]!=S[j+1]):
                geun+=1
    else:
        k=0
        while(k+i<N):
            for l in range(1,i):
                if(S[k]!=S[k+l]):
                    k+=l
                    break
            else:
                geun+=i
                k+=i
print(geun)