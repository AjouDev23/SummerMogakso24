import sys
n=int(sys.stdin.readline())
n+=1
words = str(n)
if '0' in words:
    length=len(words)
    for i in range(length):
        if words[i]=='0':
            words=words[0:i]
            while i<length:
                words+='1'
                i+=1
            break
    print(int(words))
else:
    print(n)