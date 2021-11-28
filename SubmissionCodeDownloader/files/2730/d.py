from itertools import permutations
#import numpy
import operator
def dot_product(v1, v2):
    v2 = list(map(list,zip(*v2)))
    v3 = []
    for l1 in v1:
        v3.append([sum(map(operator.mul, l1, l2)) for l2 in v2])
    return v3

N = int(input())
A = [-1, [],[],[]]
S = [-1, set(),set(),set()]
for i in range(N*3):
    A[i//N+1].append(list(map(int,input().split())))
#for a in [1,2,3]:
#    A[a] = numpy.array(A[a])

print(dot_product(A[1],A[2]))

for p in permutations([1,2,3],3):

    if dot_product(A[p[0]],A[p[1]]) == A[p[2]]:
        S[p[0]].add('X')
        S[p[1]].add('Y')
        S[p[2]].add('Z')
print(S)
for s in [1,2,3]:
    tmp = 0
    if 'X' in S[s]:
        tmp += 1
    if 'Y' in S[s]:
        tmp += 2
    if 'Z' in S[s]:
        tmp += 4
    print(tmp)