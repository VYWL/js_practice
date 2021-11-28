import sys

input = sys.stdin.readline

N, M = map(int, input().split())
errors = [*map(int, input().split()), 0]
X, Y = map(int, input().split())
errors.sort()
terms = [0]
dp = []
for i in range(1, len(errors)):
    terms.append(errors[i] - errors[i - 1])
for i in range(1, len(errors)):
    terms[i] += terms[i - 1]
for i in range(Y, len(errors)):
    dp.append(terms[i] - terms[i - Y - 1] - 1)

cur = Y
max_num = max(dp)
success = max_num >= X
while not success:
    cur += 1
    for i in range(cur, len(errors)):
        max_num = max(max_num, terms[i] - terms[i - cur - 1] - 1)
        if max_num >= X:
            success = True
            break
print(M - cur)
