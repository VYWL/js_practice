from itertools import permutations
import numpy
N = int(input())
A = [-1, [],[],[]]
S = [-1, set(),set(),set()]
for i in range(N*3):
    A[i//2+1].append(list(map(int,input().split())))
for a in [1,2,3]:
    A[a] = numpy.array(A[a])
for p in permutations([1,2,3],3):
    if (A[p[0]] @ A[p[1]] == A[p[2]]).all():
        S[p[0]].add('X')
        S[p[1]].add('Y')
        S[p[2]].add('Z')
for s in [1,2,3]:
    tmp = 0
    if 'X' in S[s]:
        tmp += 1
    if 'Y' in S[s]:
        tmp += 2
    if 'Z' in S[s]:
        tmp += 4
    print(tmp)