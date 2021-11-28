import sys
import copy
from collections import deque
import heapq
import math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
printf = sys.stdout.write

numL, numE = map(int, input().split())
err = list(map(int, input().split()))
err.sort()

noE, solveE = map(int, input().split())
start = 0
minE = 10**8
for i in range(1,len(err)):
    if(err[i] - err[start]-1 <noE):
        continue
    else:
        # print('s,i:', start, i)
        minE = min(minE, i-start-1)
        # print("minE", minE)
        start += 1
if minE<solveE:
    print(numE- solveE)
else: print(numE - minE)


    







    
            



