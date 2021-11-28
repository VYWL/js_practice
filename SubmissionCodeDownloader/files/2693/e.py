

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
    # child = []

    min_mn = 123456789
    for i in range(1, int((new_area)**(1/2))+1):
        if new_area % i == 0:
            min_mn = min(min_mn, abs(i-int(new_area)/i))
            # child.append(i)
            # if int(new_area / i) != i:
            #    child.append(int(new_area/i))
    # child.sort()
    iscan = False
    if ( min_mn <= D_old + k):
        iscan =True
    
    # for i in range(0, len(child)):
    #     row = child[i]
    #     col = int(new_area/child[i])
    #     if(  abs(row-col) <= D_old + k ):
    #         iscan = True
    #         break
    if not iscan:
        print(count)
        break
    else:
        count +=1

