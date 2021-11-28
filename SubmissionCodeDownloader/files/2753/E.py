import sys

input = sys.stdin.readline
N, M, K = map(int, input().split())
cur = N * M
cnt = 0

added = True
while cur > 0 and added:
    cur -= 1
    added = False
    for i in range(int(cur ** 0.5), 0, -1):
        if cur % i == 0:
            if (cur // i - i) <= K:
                cnt += 1
                added = True
            else:
                break
print(cnt)
