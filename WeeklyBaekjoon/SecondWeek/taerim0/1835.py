import sys

N = int(sys.stdin.readline())
cards = list(range(1, N + 1))
index = [0 for i in range(N)]

for i in range(1, N + 1):
    for _ in range(i):
        cards.append(cards.pop(0))
    index[cards[0] - 1] = i
    cards.pop(0)

for card in index:
    print(card, end=" ")