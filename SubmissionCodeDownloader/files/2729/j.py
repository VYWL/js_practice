import sys
from queue import deque
from copy import deepcopy

N = int(input())
connectVertex = [{} for _ in range(N)]
connectVertexNum = [0] * N

for i in range(N - 1):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    connectVertex[a][b] = True
    connectVertex[b][a] = True
    connectVertexNum[a] += 1
    connectVertexNum[b] += 1

Q = deque([])
for i in range(N):
    if connectVertexNum[i] == 1: # 가장자리 정점들만 가짐
        Q.append(i)
tempQ = deepcopy(Q)

while len(tempQ) > 2:
    Q = deepcopy(tempQ)
    tempQ = deque([])
    while Q:
        temp = Q.popleft()
        if connectVertexNum[temp] == 0:
            continue
        
        connectVertexNum[temp] -= 1
        
        tempVertex = list(connectVertex[temp].keys())[0] # 가장자리 정점과 연결된 정점번호
        del connectVertex[tempVertex][temp] # temp와 연결된 것 삭제
        connectVertexNum[tempVertex] -= 1
        
        if connectVertexNum[tempVertex] == 1:
            tempQ.append(tempVertex)
    
result = ""
for i in range(N):
    if connectVertexNum[i] >= 1:
        result += (str(i) + " ")
        
print(result[:-1])