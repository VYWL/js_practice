import sys;input=sys.stdin.readline;import math
N, M, K = map(int, input().split())
area = N*M
ans = 0

while True:
    if area == 1:
        break

    area -= 1
    flag = False
    for i in range(math.floor(math.sqrt(area)), 0, -1):
        if area % i == 0:
            if abs(area // i - i) <= K:
                flag = True
                break
            else:
                break
    if not flag:
        break

    ans += 1
print(ans)