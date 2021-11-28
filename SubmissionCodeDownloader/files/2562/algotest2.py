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
while(solveE <= numE):
    for i in range(len(err)-solveE):
        if (err[i+solveE] - err[i]-1 >= noE):
            print(numE-solveE)
            quit(0)
    solveE += 1        

    







    
            



