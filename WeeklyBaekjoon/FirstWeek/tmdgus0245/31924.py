def check(y,x):
    numOfMobis=0
    if(Mobis[y-1][x-1]=='O'):
        if(Mobis[y-2][x-2]=='B'):
            if(Mobis[y-3][x-3]=='I'):
                if(Mobis[y-4][x-4]=='S'):
                    numOfMobis+=1
    if(Mobis[y-1][x]=='O'):
        if(Mobis[y-2][x]=='B'):
            if(Mobis[y-3][x]=='I'):
                if(Mobis[y-4][x]=='S'):
                    numOfMobis+=1
    if(Mobis[y-1][x+1]=='O'):
        if(Mobis[y-2][x+2]=='B'):
            if(Mobis[y-3][x+3]=='I'):
                if(Mobis[y-4][x+4]=='S'):
                    numOfMobis+=1
    if(Mobis[y][x-1]=='O'):
        if(Mobis[y][x-2]=='B'):
            if(Mobis[y][x-3]=='I'):
                if(Mobis[y][x-4]=='S'):
                    numOfMobis+=1
    if(Mobis[y][x+1]=='O'):
        if(Mobis[y][x+2]=='B'):
            if(Mobis[y][x+3]=='I'):
                if(Mobis[y][x+4]=='S'):
                    numOfMobis+=1
    if(Mobis[y+1][x-1]=='O'):
        if(Mobis[y+2][x-2]=='B'):
            if(Mobis[y+3][x-3]=='I'):
                if(Mobis[y+4][x-4]=='S'):
                    numOfMobis+=1
    if(Mobis[y+1][x]=='O'):
        if(Mobis[y+2][x]=='B'):
            if(Mobis[y+3][x]=='I'):
                if(Mobis[y+4][x]=='S'):
                    numOfMobis+=1
    if(Mobis[y+1][x+1]=='O'):
        if(Mobis[y+2][x+2]=='B'):
            if(Mobis[y+3][x+3]=='I'):
                if(Mobis[y+4][x+4]=='S'):
                    numOfMobis+=1
    return numOfMobis;  

N=int(input())
result=0
Mobis = [[]*N]*N
for i in range(N):
    Mobis[i] = input()
if(N<9):
    print(0)
else:
    for j in range((N-8)**2):
        if(Mobis[j//(N-8)+4][j%(N-8)+4]=='M'):
            result += check(j//(N-8)+4,j%(N-8)+4)
    print(result)