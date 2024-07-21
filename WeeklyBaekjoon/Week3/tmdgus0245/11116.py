N=int(input())
for i in range(N):
    check=0
    M=int(input())
    leftRecord = list(map(int,input().split()))
    rightRecord = list(map(int,input().split()))
    for record in leftRecord:
        if record+1000 in rightRecord:
            check+=1
    print(check//2)
