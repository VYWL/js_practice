import sys
import copy
from collections import deque
import heapq
import math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
printf = sys.stdout.write

numV = int(input())
maxnum = 10**10
E = [[] for _ in range(numV)]
for _ in range(numV-1):
    u,v,w = map(int, input().split())
    E[u].append([v,w])
    E[v].append([u,w])
target = []
for i in range(numV):
    if len(E[i]) == 1:
        target.append(i)
    
def dji(initV):
    dist = [maxnum for _ in range(numV+1)]
    q = []
    heapq.heappush(q, [0, initV])
    while(q):
        w, v= heapq.heappop(q)
        if w > dist[v]:
            continue
        else:
            for adjV, adjW in E[v]:
                if dist[adjV] > adjW+w:
                    dist[adjV] = w+adjW
                    heapq.heappush(q, [adjW+w, adjV])
    retm = maxnum
    retM = 0
    for t in target:
        if t == initV:
            continue
        retm = min(dist[t], retm)
        if dist[t] != maxnum:
            retM = max(dist[t], retM)
    return [retm, retM]

minAns = maxnum
maxAns = 0
for t in target:
    m, M = dji(t)
    minAns = min(minAns,m)
    maxAns = max(maxAns,M)
print(maxAns)
print(minAns)