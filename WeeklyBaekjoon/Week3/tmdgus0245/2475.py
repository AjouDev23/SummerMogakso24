unique = list(map(int,input().split()))
square = 0
for num in unique:
    square += num**2
print(square % 10)