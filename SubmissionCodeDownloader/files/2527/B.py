import sys

input = sys.stdin.readline

N, M = map(int, input().split())
errors = [*map(int, input().split())]
X, Y = map(int, input().split())
errors.sort()
term = 0
for i in range(1, len(errors)):
    term = max(term, errors[i] - errors[i - 1])

print(M - max(min(X - term, 0), Y))
