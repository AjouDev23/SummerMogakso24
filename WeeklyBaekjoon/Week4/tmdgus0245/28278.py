import sys
from collections import deque
stack = deque([])
for _ in range(int(sys.stdin.readline())):
    order = sys.stdin.readline()
    if order[0] == '1':
        stack.append(int(order[2:]))
    elif order[0] == '2':
        if stack:
            print(stack.pop())
        else:
            print(-1)
    elif order[0] == '3':
        print(len(stack))
    elif order[0] == '4':
        if stack:
            print(0)
        else:
            print(1)
    else:
        if stack:
            print(stack[len(stack)-1])
        else:
            print(-1)