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

    tmp = []
    for i in range(4):
        tmp.append(chairs[now[0]+x[i]][now[1]+y[i]])
    tmp.sort()
    #print(tmp)
    if len(mins)<2:
        mins.append(tmp[1])
    elif mins[0] < tmp[1] < mins[1]:
        mins[1] = tmp[1]
    elif tmp[1] < mins[0]:
        mins[1] = mins[0]
        mins[0] = tmp[1]

    for i in range(3):
        if [now[0]+dx[i],now[1]+dy[i]] not in queue and not (now[0]+dx[i] > N-1 or now[1]+dy[i] > N-1):
            queue.append([now[0]+dx[i],now[1]+dy[i]])
if len(mins) == 1:
    print(mins[0])
else:
    print(mins[1])
