import sys
N = int(sys.stdin.readline())
LRstack=[]
SKstack=[]
result=0
skills = list(sys.stdin.readline().rstrip())
for skill in skills:
    if 48<ord(skill)<58:
        result+=1
    elif skill == 'S':
        SKstack.append(skill)
    elif skill == 'K':
        if not SKstack:
            break
        else:
            SKstack.pop()
            result+=1
    elif skill == 'L':
        LRstack.append(skill)
    else:
        if not LRstack:
            break
        else:
            LRstack.pop()
            result+=1
print(result)              