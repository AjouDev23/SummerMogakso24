import sys

N, M, K = map(int, sys.stdin.readline().split())

blackFullCnt = [[0]]
whiteFullCnt = [[0]]
MinCnt = 100000000

for f in range(1, N + 1):
    line = sys.stdin.readline()

    blackRowCnt = [0]
    whiteRowCnt = [0]

    Flag = (f + 1) % 2

    for i in range(1, M + 1):
        if (line[i - 1] == 'B' and not Flag) or (line[i - 1] == 'W' and Flag):
            blackRowCnt.append(blackRowCnt[i - 1])
            whiteRowCnt.append(whiteRowCnt[i - 1] + 1)
        else:
            blackRowCnt.append(blackRowCnt[i - 1] + 1)
            whiteRowCnt.append(whiteRowCnt[i - 1])
        Flag = not Flag

        if f > 1:
            blackRowCnt[i] += (blackFullCnt[f - 1][i] - blackFullCnt[f - 1][i - 1])
            whiteRowCnt[i] += (whiteFullCnt[f - 1][i] - whiteFullCnt[f - 1][i - 1])

        if i > K - 1 and f > K - 1:
            if i > K and f > K:
                blackVal = blackRowCnt[i] - blackRowCnt[i - K] - blackFullCnt[f - K][i] + blackFullCnt[f - K][i - K]
                whiteVal = whiteRowCnt[i] - whiteRowCnt[i - K] - whiteFullCnt[f - K][i] + whiteFullCnt[f - K][i - K]
            elif i > K:
                blackVal = blackRowCnt[i] - blackRowCnt[i - K]
                whiteVal = whiteRowCnt[i] - whiteRowCnt[i - K]
            elif f > K:
                blackVal = blackRowCnt[i] - blackFullCnt[f - K][i]
                whiteVal = whiteRowCnt[i] - whiteFullCnt[f - K][i]
            else:
                blackVal = blackRowCnt[i]
                whiteVal = whiteRowCnt[i]

            if blackVal < MinCnt:
                MinCnt = blackVal
            if whiteVal < MinCnt:
                MinCnt = whiteVal

    blackFullCnt.append(blackRowCnt)
    whiteFullCnt.append(whiteRowCnt)

print(MinCnt)