from collections import deque
N = int(input())
chairs = []
for _ in range(N):
    chairs.append(list(map(int,input().split())))
start = [0,0]
x = [0,0,1,1]
y = [0,1,0,1]
dx = [0,2,2]
dy = [2,0,2]
mins = []

queue = deque([start])
while queue:
    now = queue.popleft()

    if now[0] > N-1 or now[1] > N-1:
        continue

    tmp = []
    for i in range(4):
        tmp.append(chairs[now[0]+x[i]][now[1]+y[i]])
    tmp.sort()
    mins.append(tmp[1])

    for i in range(3):
        if [now[0]+dx[i],now[1]+dy[i]] not in queue:
            queue.append([now[0]+dx[i],now[1]+dy[i]])
mins.sort()

print(mins[1])