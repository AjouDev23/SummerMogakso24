import sys

N = int(sys.stdin.readline())

Sstack = []
Lstack = []

commands = sys.stdin.readline()
cnt = 0

for i in range(N):
    command = commands[i]

    if command == 'S':
        Sstack.append(command)
    elif command == 'L':
        Lstack.append(command)
    elif command == 'K':
        if len(Sstack) > 0:
            Sstack.pop()
            cnt += 1
        else:
            break
    elif command == 'R':
        if len(Lstack) > 0:
            Lstack.pop()
            cnt += 1
        else:
            break
    else:
        cnt += 1

print(cnt)