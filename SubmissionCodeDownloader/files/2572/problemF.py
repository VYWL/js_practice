import sys;input=sys.stdin.readline
N = int(input().strip())
E = list(map(int, input().split()))
C = list(map(int, input().split()))
cafe = []
for i in range(N):
    cafe.append([C[i], E[i]])
cafe.sort()
ans = 0
for j in range(N):
    time, S = 0, 0
    for i in range(j, N):

        if cafe[i][1] - S <= 0:
            continue
        time += cafe[i][1] - S
        S += cafe[i][0]
    ans = max(ans, time)
print(ans)