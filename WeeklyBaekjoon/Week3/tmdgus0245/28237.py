n=int(input())
abcd=n+1
bd=-(n+2)
for a in range(1,n+1):
    if n%a==0:
        c=n//a
        for b in range(1,-bd+1):
            if bd%b==0:
                d=bd//b
                if abcd==a*d+c*b:
                    print(a,b,c,d)
                    exit()
print(-1)