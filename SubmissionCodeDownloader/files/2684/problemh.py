import sys;input=sys.stdin.readline

N = int(input().strip())
adj = [[] for _ in range(N)]
for _ in range(N-1):
    p, q, w = map(int, input().split())
    adj[p].append([q, w])
    adj[q].append([p, w])

maximum, minimum = float('-inf'), float('inf')


def DFS(now, cost):
    global visited, maximum, minimum



    for n, w in adj[now]:
        if not visited[n]:
            if len(adj[n]) == 1:
                maximum = max(maximum, cost+w)
                minimum = min(minimum, cost+w)
            visited[n] = True
            DFS(n, cost+w)


for i in range(N):
    if len(adj[i]) == 1:
        visited = [False] * N
        visited[i] = True
        DFS(i, 0)

print(maximum)
print(minimum)