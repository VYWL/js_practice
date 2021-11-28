import sys
import copy
from collections import deque
import heapq
import math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
printf = sys.stdout.write

N, M, K = map(int, input().split())
size = N*M
origin = size
old = max(M-N, N-M)
while(size >1):
    eaten = False
    ate = size -1
    n = int(ate ** 0.5)
    for i in range(K):
        if ate % n  == 0 and abs(abs(n - ate//n) - old)<=K:
            size -= 1
            eaten = True
            break
        n = n+1
    if eaten: continue
    break
print(origin - size)

