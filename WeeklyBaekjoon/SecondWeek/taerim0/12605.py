import sys

N = int(sys.stdin.readline())

for i in range(N):
    WordList = list(map(str, sys.stdin.readline().strip().split()))
    WordList.reverse()
    print("Case #" + str(i + 1) + ":", end=" ")
    for word in WordList:
        print(word, end=" ")
    print("")