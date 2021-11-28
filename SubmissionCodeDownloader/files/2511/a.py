a = input()
b = ""
for i in range(0,len(a)):
    b += a[i] + "__"

print(b[:-2])