import sys;input=sys.stdin.readline
N = int(input().strip())
nums = [list(map(int, input().split())) for _ in range(N)]

def backtrack(y, x, length):
    if length == 2:
        lst = [nums[y][x], nums[y][x+1], nums[y+1][x], nums[y+1][x+1]]
        lst.sort()
        return lst[1]

    lst = []
    lst.append(backtrack(y,x, length//2))
    lst.append(backtrack(y+length//2,x, length//2))
    lst.append(backtrack(y,x+length//2, length//2))
    lst.append(backtrack(y+length//2,x+length//2, length//2))
    lst.sort()
    return lst[1]

print(backtrack(0, 0, N))