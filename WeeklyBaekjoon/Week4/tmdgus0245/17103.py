import sys
gold = [0 for _ in range(1000002)]
for i in range(2,1000001):
    if gold[i]==0:
        gold[i]=1
        for j in range(2,1000001//i+1):
            gold[j*i]=2
for _ in range(int(sys.stdin.readline())):
    count = 0
    num = int(sys.stdin.readline())
    for x in range(2,num//2+1):
        if gold[x] == 1 and gold[num-x] == 1:
            count += 1
    print(count)