N = int(input())
string = input()
accumulate = 0
for i in range(N):
    accumulate += (ord(string[i]) - ord('a') + 1) * 31 ** i
    if accumulate > 1234567891:
        accumulate %= 1234567891
print(accumulate)