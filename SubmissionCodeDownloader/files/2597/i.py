import sys

def findOne(tempArr):
    if len(tempArr) == 1:
        return tempArr[0][0]
    elif len(tempArr) == 2:
        t = [tempArr[0][0], tempArr[0][1], tempArr[1][0], tempArr[1][1]]
        t.sort()
        return t[1]
    else:
        a = []
        b = []
        c = []
        d = []
        
        for i in range(len(tempArr)//2):
            a.append(tempArr[i][:len(tempArr)//2])
            b.append(tempArr[i][len(tempArr)//2:])
        for i in range(len(tempArr)//2, len(tempArr)):
            c.append(tempArr[i][:len(tempArr)//2])
            d.append(tempArr[i][len(tempArr)//2:])
        
        t = [findOne(a), findOne(b), findOne(c), findOne(d)]
        t.sort()
        return t[1]

N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, sys.stdin.readline().rstrip().split())))
print(findOne(arr))