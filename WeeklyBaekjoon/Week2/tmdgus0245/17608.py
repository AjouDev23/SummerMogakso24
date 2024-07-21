import sys
N=int(sys.stdin.readline())
lst = []
result=0
for _ in range(N):
    lst.append(int(sys.stdin.readline()))
j=0
for i in lst[::-1]:
    if(i>j):
        result+=1
        j=i
print(result)