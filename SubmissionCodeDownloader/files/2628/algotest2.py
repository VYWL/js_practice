import sys
import copy
from collections import deque
import heapq
import math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
printf = sys.stdout.write

numL, numE = map(int, input().split())
err = [0] + list(map(int, input().split())) +[numL+1]
err.sort()


noE, solveE = map(int, input().split())
start = 0
minE = 10**8
# if(err[0]-1-1>= noE or numL - err[-1] -1 >= noE):
#     print(numE-solveE)

for i in range(1,len(err)):
    if(err[i] - err[start]-1 <noE):
        # print("con", err[i], err[stasrt])
        continue
    else:
        while(err[i] - err[start] -1 >= noE):
            start += 1
        start -= 1
        # print('s,i:', start, i)
        minE = min(minE, i-start-1)
        # print("minE", minE)
            

if minE<solveE:
    print(numE- solveE)
else: print(numE - minE)


    







    
            



