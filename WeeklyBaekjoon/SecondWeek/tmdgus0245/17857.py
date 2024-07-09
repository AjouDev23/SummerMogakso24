import sys
N = int(sys.stdin.readline())
FavoriteSong= list(map(int,sys.stdin.readline().split()))
lst=[[0,0]for _ in range(N)]
for i in range(N):
    lst[i][0]=i+1
    lst[i][1]=FavoriteSong[i]
start=0
for i in range(N-1):
    if((start+lst[start][1]%(N-i))%(N-i)==0):
        lst.pop(N-i-1)
        start=0
    else:
        if start>(start+lst[start][1]%(N-i)-1)%(N-i):
            lst.pop((start+lst[start][1]%(N-i)-1)%(N-i))
            if(len(lst)==1):
                break
            start=(start+lst[start-1][1]%(N-i)-1)%(N-i)
        elif start==(start+lst[start][1]%(N-i)-1)%(N-i):
            lst.pop((start+lst[start][1]%(N-i)-1)%(N-i))
            start=start
        else:
            lst.pop((start+lst[start][1]%(N-i)-1)%(N-i))
            if(len(lst)==1):
                break
            start=(start+lst[start][1]%(N-i)-1)%(N-i)
print(lst[0][0])