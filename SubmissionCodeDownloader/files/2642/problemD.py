import sys;input=sys.stdin.readline
N = int(input().strip())
mat0 = [list(map(int, input().split())) for _ in range(N)]
mat1 = [list(map(int, input().split())) for _ in range(N)]
mat2 = [list(map(int, input().split())) for _ in range(N)]

def mat_mult(a, b):
    result = [[0] * (N) for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                result[i][j] = result[i][j] + a[i][k] * b[k][j]

    return result


def matching(a, b):
    for i in range(N):
        if a[i] != b[i]:
            return False
    return True

# 0은 평문, 1은 암호화행렬, 2는 암호문
result = [[], [], []]

r = mat_mult(mat0, mat1)
if matching(r, mat2):
    result[0].append(0)
    result[1].append(1)
    result[2].append(2)

r = mat_mult(mat0, mat2)
if matching(r, mat1):
    result[0].append(0)
    result[2].append(1)
    result[1].append(2)

r = mat_mult(mat1, mat0)
if matching(r, mat2):
    result[1].append(0)
    result[0].append(1)
    result[2].append(2)

r = mat_mult(mat1, mat2)
if matching(r, mat0):
    result[1].append(0)
    result[2].append(1)
    result[0].append(2)

r = mat_mult(mat2, mat0)
if matching(r, mat1):
    result[2].append(0)
    result[0].append(1)
    result[1].append(2)

r = mat_mult(mat2, mat1)
if matching(r, mat0):
    result[2].append(0)
    result[1].append(1)
    result[0].append(2)

for i in range(3):
    ans = 0
    if 0 in result[i]:
        ans += 1
    if 1 in result[i]:
        ans += 2
    if 2 in result[i]:
        ans += 4
    print(ans)