N = int(input())
state = [0 for _ in range(N)]
note = list(map(int,input().split()))
count = 0
for i in range(N):
    if note[i] != state[i]:
        count+=1
        state[i]^=1
        if i+1 == N:
            continue
        state[i+1]^=1
        if i+2 == N:
            continue
        state[i+2]^=1
print(count)