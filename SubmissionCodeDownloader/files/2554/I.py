import sys

input = sys.stdin.readline
N = int(input())
table = [[*map(int, input().split())] for _ in range(N)]


def find(X, Y, length):
    if length == 2:
        return \
            sorted(
                [table[X][Y], table[X][Y + 1], table[X + 1][Y], table[X + 1][Y + 1]])[1]
    nl = length // 2
    return sorted([
        find(X, Y, nl),
        find(X + nl, Y, nl),
        find(X, Y + nl, nl),
        find(X + nl, Y + nl, nl),
    ]
    )[1]


print(find(0, 0, N))
