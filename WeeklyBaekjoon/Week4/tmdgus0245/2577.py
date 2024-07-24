A=int(input())
B=int(input())
C=int(input())
result = A*B*C
string = str(result)
for i in "0123456789":
    print(string.count(i))