N=int(input())
for i in range(N):
    words = list(input().split())
    print("Case #",i+1,": ",sep='',end="")
    for word in words[::-1]:
        print(word,end=' ')
    print()