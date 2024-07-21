import sys
N,M=map(int,sys.stdin.readline().split())
check=1
for i in range(N):
    next = sys.stdin.readline().rstrip()
    if i==0:
        base = next[0:M]
        continue
    else:
        for i in range(1,M+1):
            if base[0:i]==next[M-i:]:
                break
            elif base[M-i:]==next[0:i]:
                break
        else:
            check=0
        base = next[0:M]
if check==0:
    print(0)
else:
    print(1)