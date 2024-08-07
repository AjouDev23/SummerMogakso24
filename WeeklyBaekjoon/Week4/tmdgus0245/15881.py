N = input()
List = input()
count = 0
while "pPAp" in List:
    count+=1
    List = List[List.find("pPAp")+4:]
print(count)