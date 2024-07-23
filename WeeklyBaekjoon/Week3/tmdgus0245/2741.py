ABC = [0,0,0]
for i in range(3):
    ABC[i] = int(input())
print(ABC[0] + ABC[1] - ABC[2], int(str(ABC[0]) + str(ABC[1])) - ABC[2], sep = '\n')