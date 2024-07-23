N = input()
count = 0
milkWay = list(map(int,input().split()))
turn = 0
for milk in milkWay:
    if milk == turn:
        count += 1
        turn = (turn + 1) % 3
print(count)