import sys

c = int(sys.stdin.readline())

result = 0
base = [1]
spicy = [1]
Now_Spicy = 0

while base[-1] <= c:
    base.append(base[-1] * 7)
    spicy_calcul = 1
    for item in spicy:
        spicy_calcul += item * 2
    spicy.append(spicy_calcul)
for i in range(len(base) - 2, -1, -1):
    if c - Now_Spicy >= base[i]:
        result += spicy[i] * min(2, (c - Now_Spicy) // base[i])
        Now_Spicy += base[i] * min(2, (c - Now_Spicy) // base[i])
print(result)