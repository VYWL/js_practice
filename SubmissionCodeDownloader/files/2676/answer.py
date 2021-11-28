# -*- coding: utf-8 -*-

n = int(input())
count = {i:0 for i in range(n)}
tree = {i:set() for i in range(n)}

for i in range(n-1):
    a, b = map(int, input().split())
    count[a] += 1
    count[b] += 1
    tree[a].add(b)
    tree[b].add(a)

d = {i for i in range(n) if count[i] == 1}
while max(set(count.values())) > 2:
    new = set()
    for j in d:
        count[j] = 0
        del count[j]
        c = sum(tree[j])
        tree[c].remove(j)
        count[c] -= 1
        if count[c] == 1:
            new.add(c)
    d = new
print(sorted(list(count.keys())))
