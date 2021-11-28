

a = input()
a = a.split()
n = int(a[0])
m = int(a[1])
k = int(a[2])
count = 0
new_area = n*m
D_old = abs(n-m)

while True:
    new_area -= 1
    if new_area == 0:
        print(count)
        break
    child = []
    for i in range(1, int((new_area)**(1/2))+1):
        if new_area %i == 0:
            child.append(i)
            if int(new_area / i) != i:
               child.append(int(new_area/i))
    child.sort()

    iscan = False
    for i in range(0, int(len(child)/2)+1):
        row = child[i]
        col = int(new_area/child[i])
        if(  abs(row-col) <= D_old + k ):
            iscan = True
    if not iscan:
        print(count)
        break
    else:
        count +=1

