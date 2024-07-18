import sys
N = int(sys.stdin.readline())
card = [0]*N
index=0
for i in range(1,N):
    count=i
    while(count or card[index]!=0):
        if card[index]==0:
            count-=1
            index = (index+1)%N
        else:
            index = (index+1)%N
    card[index]=i
    index = (index+1)%N
for j in range(N):
    if card[j]==0:
        card[j]=N
        break
print(*card)