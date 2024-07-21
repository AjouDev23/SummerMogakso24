import sys

n = int(sys.stdin.readline())
n += 1
sn = str(n)
for i in range(len(sn)):
    if sn[i] == '0':
        sn = list(sn)
        for j in range(i, len(sn)):
            sn[j] = '1'
print(''.join(sn))