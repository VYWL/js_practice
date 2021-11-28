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
    # print("ate: ", ate, "n:", n)
    for i in range(1, n+1):
        # print("i, ",i)
        if ate % i  == 0:
            if ate//i-i - old <= K:
                # print(i, ate//i)
                eaten = True
                size -= 1
                # print(size)
                break
    if eaten: continue
    break
print(origin - size)

