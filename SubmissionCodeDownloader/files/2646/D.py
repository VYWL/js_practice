import sys


def matrix_mul(a, b):
    result = []
    for i in range(len(a)):
        temp = []
        for j in range(len(b[0])):
            value = 0
            for k in range(len(b)):
                value += a[i][k] * b[k][j]
            temp.append(value)
        result.append(temp)
    return result


def is_same(A, B):
    for i in range(len(A)):
        if A[i] != B[i]:
            return False
    return True


input = sys.stdin.readline

N = int(input())
matrix = [[[*map(int, input().split())] for _ in range(N)] for _ in range(3)]
keys = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
# 0 1 2
if is_same(matrix_mul(matrix[0], matrix[1]), matrix[2]):
    keys[0][0] = 1
    keys[1][1] = 1
    keys[2][2] = 1
# 0 2 1
if is_same(matrix_mul(matrix[0], matrix[2]), matrix[1]):
    keys[0][0] = 1
    keys[2][1] = 1
    keys[1][2] = 1
# 1 2 0
if is_same(matrix_mul(matrix[1], matrix[2]), matrix[0]):
    keys[1][0] = 1
    keys[2][1] = 1
    keys[0][2] = 1
# 1 0 2
if is_same(matrix_mul(matrix[1], matrix[0]), matrix[2]):
    keys[1][0] = 1
    keys[0][1] = 1
    keys[2][2] = 1
# 2 0 1
if is_same(matrix_mul(matrix[2], matrix[0]), matrix[1]):
    keys[2][0] = 1
    keys[0][1] = 1
    keys[1][2] = 1
# 2 1 0
if is_same(matrix_mul(matrix[2], matrix[1]), matrix[0]):
    keys[2][0] = 1
    keys[1][1] = 1
    keys[0][2] = 1

for i in range(3):
    print(keys[i][0] + 2 * keys[i][1] + 4 * keys[i][2])
