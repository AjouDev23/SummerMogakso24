T = int(input())
for _ in range(T):
    count1 = 0
    count2 = 0
    binaryNum = list(input().split())
    for i in range(len(binaryNum[0])):
        if binaryNum[0][i] != binaryNum[1][i]:
            if binaryNum[0][i] == '0':
                count1 += 1
            else:
                count2 += 1
    print(max(count2,count1))