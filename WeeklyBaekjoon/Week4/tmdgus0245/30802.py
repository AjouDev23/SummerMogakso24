N = int(input())
size = list(map(int,input().split()))
T,P = map(int,input().split())
Tset = 0
for t in size:
    Tset += t // T
    if t % T:
        Tset += 1
Pset = N // P
each = N % P
print(Tset)
print(Pset,each,sep=' ')