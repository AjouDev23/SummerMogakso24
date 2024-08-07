for _ in range(int(input())):
    result = input()
    count = 0
    grade = 0
    for o in result:
        if o == 'O':
            grade+=1+count
            count+=1
        else:
            count = 0
    print(grade)