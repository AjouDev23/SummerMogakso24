def check(y,x):
    numOfMobis=0
    if(y>3):
        if(x>3):
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
        if(x<N-4):
            if(Mobis[y-1][x+1]=='O'):
                if(Mobis[y-2][x+2]=='B'):
                    if(Mobis[y-3][x+3]=='I'):
                        if(Mobis[y-4][x+4]=='S'):
                            numOfMobis+=1
    if(x>3):
        if(Mobis[y][x-1]=='O'):
            if(Mobis[y][x-2]=='B'):
                if(Mobis[y][x-3]=='I'):
                    if(Mobis[y][x-4]=='S'):
                        numOfMobis+=1
    if(x<N-4):
        if(Mobis[y][x+1]=='O'):
            if(Mobis[y][x+2]=='B'):
                if(Mobis[y][x+3]=='I'):
                    if(Mobis[y][x+4]=='S'):
                        numOfMobis+=1
    if(y<N-4):
        if(x>3):
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
        if(x<N-4):
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
if(N<5):
    print(0)
else:
    for j in range(N):
        for k in range(N):
            if(Mobis[j][k]=='M'):
                result += check(j,k)
    print(result)