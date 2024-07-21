import sys
from collections import deque
N,M=map(int,sys.stdin.readline().split())
maze = [0]*N
for i in range(N):
    maze[i] = sys.stdin.readline().rstrip()
for y in range(N):
    for x in range(M):
        if maze[y][x]=='0':
            queue = deque([(y,x,0,0,0,0)])
while queue:
    position = queue.popleft()
    y = position[0]
    x = position[1]
    count = position[2]
    key = position[3]
    pre = position[4]
    visited = position[5]
    if y>0 and not((pre >> 2) & 1):
        if maze[y-1][x] == '.' or maze[y-1][x] == '0':
            queue.append((y-1,x,count+1,key,1,visited))
        elif ord('a') <= ord(maze[y-1][x]) <= ord('f'):
            if (key >> (ord(maze[y-1][x]) - ord('a'))) & 1:
                queue.append((y-1,x,count+1,key,1,visited))
            else:
                queue.append((y-1,x,count+1,key | int(2**(ord(maze[y-1][x])-ord('a'))),0,0))
        elif ord('A') <= ord(maze[y-1][x]) <= ord('F'):
            if not((visited >> (ord(maze[y-1][x]) - ord('A'))) & 1):
                if (key >> (ord(maze[y-1][x]) - ord('A'))) & 1:
                    queue.append((y-1,x,count+1,key,1,visited | int(2**(ord(maze[y-1][x])-ord('A')))))
        elif maze[y-1][x] == '1':
            print(count+1)
            exit()
    if x>0 and not((pre >> 3) & 1):
        if maze[y][x-1] == '.' or maze[y][x-1] == '0':
            queue.append((y,x-1,count+1,key,2,visited))
        elif ord('a') <= ord(maze[y][x-1]) <= ord('f'):
            if (key >> (ord(maze[y][x-1]) - ord('a'))) & 1:
                queue.append((y,x-1,count+1,key,2,visited))
            else:
                queue.append((y,x-1,count+1,key | int(2**(ord(maze[y][x-1])-ord('a'))),0,0))
        elif ord('A') <= ord(maze[y][x-1]) <= ord('F'):
            if not((visited >> (ord(maze[y][x-1]) - ord('A'))) & 1):
                if (key >> (ord(maze[y][x-1]) - ord('A'))) & 1:
                    queue.append((y,x-1,count+1,key,2,visited | int(2**(ord(maze[y][x-1])-ord('A')))))
        elif maze[y][x-1] == '1':
            print(count+1)
            exit()
    if y<N-1 and not(pre & 1):
        if maze[y+1][x] == '.' or maze[y+1][x] == '0':
            queue.append((y+1,x,count+1,key,4,visited))
        elif ord('a') <= ord(maze[y+1][x]) <= ord('f'):
            if (key >> (ord(maze[y+1][x]) - ord('a'))) & 1:
                queue.append((y+1,x,count+1,key,4,visited))
            else:
                queue.append((y+1,x,count+1,key | int(2**(ord(maze[y+1][x])-ord('a'))),0,0))
        elif ord('A') <= ord(maze[y+1][x]) <= ord('F'):
            if not((visited >> (ord(maze[y+1][x]) - ord('A'))) & 1):
                if (key >> (ord(maze[y+1][x]) - ord('A'))) & 1:
                    queue.append((y+1,x,count+1,key,4,visited | int(2**(ord(maze[y+1][x])-ord('A')))))
        elif maze[y+1][x] == '1':
            print(count+1)
            exit()
    if x<M-1 and not((pre >> 1) & 1):
        if maze[y][x+1] == '.' or maze[y][x+1] == '0':
            queue.append((y,x+1,count+1,key,8,visited))
        elif ord('a') <= ord(maze[y][x+1]) <= ord('f'):
            if (key >> (ord(maze[y][x+1]) - ord('a'))) & 1:
                queue.append((y,x+1,count+1,key,8,visited))
            else:
                queue.append((y,x+1,count+1,key | int(2**(ord(maze[y][x+1])-ord('a'))),0,0))
        elif ord('A') <= ord(maze[y][x+1]) <= ord('F'):
            if not((visited >> (ord(maze[y][x+1]) - ord('A'))) & 1):
                if (key >> (ord(maze[y][x+1]) - ord('A'))) & 1:
                    queue.append((y,x+1,count+1,key,8,visited | int(2**(ord(maze[y][x+1])-ord('A')))))
        elif maze[y][x+1] == '1':
            print(count+1)
            exit()
    if not queue:
        print(-1)