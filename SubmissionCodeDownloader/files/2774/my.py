import sys
import copy
from collections import deque
import heapq
import math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
printf = sys.stdout.write

N = int(input())
arr1= list(map(int, input().split()))
arr2 = list(map(int, input().split()))
arr = []
for a,b in zip(arr1, arr2):
    arr.append([a,b])
arr.sort(key=lambda x :x[1])
time = 0
down = 0
for a,b in arr:
    if a-down > 0:
        time += (a-down)
        down += b
    else: break
print(time)