N = int(input())
arr = [[]]
for i in range(N):
    arr.append([0]+list(map(int, input().split())))

def recur(x1, x2, y1, y2):
    if x2-x1 == 1:
        temp = [arr[y1][x1], arr[y1][x2], arr[y2][x1], arr[y2][x2]]
        temp.sort()
        # print(temp)
        # print(temp[1])
        return temp[1]
    else:
        temp = [recur(x1, x1 + ((x2-x1)+1)//2 -1, y1, y1+(y2-y1+1)//2-1),
             recur(x1 + ((x2-x1)+1)//2, x2, y1,y1+(y2-y1+1)//2-1),
             recur(x1, x1 + ((x2-x1)+1)//2 -1, y1+(y2-y1+1)//2, y2),
             recur(x1 +((x2-x1)+1)//2, x2, y1+(y2-y1+1)//2, y2)]
        temp.sort()
        return temp[1]

print(recur(1, N, 1, N))