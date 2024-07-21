import sys
N=int(sys.stdin.readline())
S=sys.stdin.readline()
geunNum=0
s = S.find('2')
while(s!=-1):
    e=s
    while(e!='\n'):
        if(S[e+1]=='2'):
            e+=1
        else:
            break
    i=e-s+1
    geunNum += i*(i+1)*(i+2)//6
    S=S[e+1:]
    s = S.find('2')
print(geunNum)