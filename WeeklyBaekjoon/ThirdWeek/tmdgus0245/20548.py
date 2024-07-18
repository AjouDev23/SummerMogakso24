N=int(input())
result=N%7
N-=N%7
for i in range(13,0,-1):
    for j in range(2,0,-1):
        if N>=7**i*j:
            result+=3**i*j
            N-=7**i*j
print(result)