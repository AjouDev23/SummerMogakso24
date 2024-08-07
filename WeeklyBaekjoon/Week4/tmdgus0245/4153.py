sides = list(map(int,input().split()))
sides.sort()
while sides[2]:
    if sides[0]**2 + sides[1]**2 == sides[2]**2:
        print("right")
    else:
        print("wrong")
    sides = list(map(int,input().split()))
    sides.sort()