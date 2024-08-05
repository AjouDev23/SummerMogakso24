num = input()
while int(num):
    if ''.join(reversed(num)) == num:
        print("yes")
    else:
        print("no")
    num = input()