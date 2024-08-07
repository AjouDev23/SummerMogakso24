import sys

N,M=map(int,sys.stdin.readline().split())
maze = [0]*N
for i in range(N):
    maze[i] = sys.stdin.readline().rstrip()
for y in range(N):
    for x in range(M):
        if maze[y][x]=='0':
            queue = [(y,x,0,0)]
visited = [[[0 for _ in range(64)]for _ in range(M)]for _ in range(N)]
while queue:
    position = queue.pop(0)
    y = position[0]
    x = position[1]
    count = position[2]
    key = position[3]
    if y>0:
        if maze[y-1][x] == '.' or maze[y-1][x] == '0':
            if not(visited[y-1][x][key]):
                queue.append((y-1,x,count+1,key))
                visited[y-1][x][key]=1
        elif ord('a') <= ord(maze[y-1][x]) <= ord('f'):
            if not(visited[y-1][x][key]):
                visited[y-1][x][key]=1
                if (key >> (ord(maze[y-1][x]) - ord('a'))) & 1:
                    queue.append((y-1,x,count+1,key))
                else:
                    queue.append((y-1,x,count+1,key | int(2**(ord(maze[y-1][x])-ord('a')))))
        elif ord('A') <= ord(maze[y-1][x]) <= ord('F'):
            if not(visited[y-1][x][key]):
                if (key >> (ord(maze[y-1][x]) - ord('A'))) & 1:
                    visited[y-1][x][key]=1
                    queue.append((y-1,x,count+1,key))
        elif maze[y-1][x] == '1':
            print(count+1)
            exit()
    if x>0:
        if maze[y][x-1] == '.' or maze[y][x-1] == '0':
            if not(visited[y][x-1][key]):
                visited[y][x-1][key]=1
                queue.append((y,x-1,count+1,key))
        elif ord('a') <= ord(maze[y][x-1]) <= ord('f'):
            if not(visited[y][x-1][key]):
                visited[y][x-1][key]=1
                if (key >> (ord(maze[y][x-1]) - ord('a'))) & 1:
                    queue.append((y,x-1,count+1,key))
                else:
                    queue.append((y,x-1,count+1,key | int(2**(ord(maze[y][x-1])-ord('a')))))
        elif ord('A') <= ord(maze[y][x-1]) <= ord('F'):
            if not(visited[y][x-1][key]):
                if (key >> (ord(maze[y][x-1]) - ord('A'))) & 1:
                    visited[y][x-1][key]=1
                    queue.append((y,x-1,count+1,key))
        elif maze[y][x-1] == '1':
            print(count+1)
            exit()
    if y<N-1:
        if maze[y+1][x] == '.' or maze[y+1][x] == '0':
            if not(visited[y+1][x][key]):
                visited[y+1][x][key]=1
                queue.append((y+1,x,count+1,key))
        elif ord('a') <= ord(maze[y+1][x]) <= ord('f'):
            if not(visited[y+1][x][key]):
                visited[y+1][x][key]=1
                if (key >> (ord(maze[y+1][x]) - ord('a'))) & 1:
                    queue.append((y+1,x,count+1,key))
                else:
                    queue.append((y+1,x,count+1,key | int(2**(ord(maze[y+1][x])-ord('a')))))
        elif ord('A') <= ord(maze[y+1][x]) <= ord('F'):
            if not(visited[y+1][x][key]):
                if (key >> (ord(maze[y+1][x]) - ord('A'))) & 1:
                    visited[y+1][x][key]=1
                    queue.append((y+1,x,count+1,key))
        elif maze[y+1][x] == '1':
            print(count+1)
            exit()
    if x<M-1:
        if maze[y][x+1] == '.' or maze[y][x+1] == '0':
            if not(visited[y][x+1][key]):
                visited[y][x+1][key]=1
                queue.append((y,x+1,count+1,key))
        elif ord('a') <= ord(maze[y][x+1]) <= ord('f'):
            if not(visited[y][x+1][key]):
                visited[y][x+1][key]=1
                if (key >> (ord(maze[y][x+1]) - ord('a'))) & 1:
                    queue.append((y,x+1,count+1,key))
                else:
                    queue.append((y,x+1,count+1,key | int(2**(ord(maze[y][x+1])-ord('a')))))
        elif ord('A') <= ord(maze[y][x+1]) <= ord('F'):
            if not(visited[y][x+1][key]):
                if (key >> (ord(maze[y][x+1]) - ord('A'))) & 1:
                    queue.append((y,x+1,count+1,key))
        elif maze[y][x+1] == '1':
            print(count+1)
            exit()
    if not queue:
        print(-1)