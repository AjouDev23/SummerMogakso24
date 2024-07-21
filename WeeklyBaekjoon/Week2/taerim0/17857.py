import sys

n = int(sys.stdin.readline())
index = 0
LastPop = -1

def make_tuple(item):
    global index
    index += 1
    return (item, index)

q = list(map(make_tuple, list(map(int, sys.stdin.readline().split()))))

while True:
    if len(q) == 1:
        print(q[0][1])
        break

    LastPop += 1
    NextPop = (q[LastPop % len(q)][0] + LastPop - 1) % len(q)
    if NextPop == len(q) - 1:
        LastPop = -1
    else:
        LastPop = NextPop - 1
    q.pop(NextPop)