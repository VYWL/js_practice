import heapq
import math

def daik(graph, start):
  distances = {node: float('inf') for node in graph}
  distances[start] = 0 
  queue = []
  heapq.heappush(queue, [distances[start], start])  

  while queue: 
    curDistance, curDestination = heapq.heappop(queue) 

    if distances[curDestination] < curDistance: 
      continue
    
    for newDestination, newDistance in graph[curDestination].items():
      distance = curDistance + newDistance  
      if distance < distances[newDestination]:  
        distances[newDestination] = distance
        heapq.heappush(queue, [distance, newDestination])  
    
  return distances

N = int(input())

TheGraph = {}

c = 1
a = '0'
lineNumber = 0
max = 0
for i in range(N):
    TheGraph[str(i)] = {}

for j in range(N-1):
    a, b, c = input().split()
    resistance = int(c)
    TheGraph[a][b] = resistance
    TheGraph[b][a] = resistance
    lineNumber += 1
    if resistance > max:
        max = resistance


min = float("inf")
max = 0

for i in range(N):
    if len(TheGraph[str(i)].keys()) == 1:
        temp = daik(TheGraph, str(i))
        for j in temp.keys():
            if len(TheGraph[str(j)].keys()) == 1:
                if temp[j] > max and 0<temp[j] and temp[j]< math.inf:
                    max = temp[j]
                if temp[j] < min and 0<temp[j] and temp[j]< math.inf:
                    min = temp[j]

print(max)
print(min)




